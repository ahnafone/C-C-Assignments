#pragma once

#define MAX 2000000000

class WordCount {
public:
    //constructor
    WordCount() {
        size = 0;
    }
    //destructor
    ~WordCount() {
        free(str_count);
    }

    //breaks the string input
    void breakString(std::string str) {
        int j = 0, len = (int) str.size();
        std::string subStr;

        for(int i = 0; i < len; i++) {
            if (str[i] == ' ') {    //separate string if space is found
                subStr = str.substr(j, i-j);
                if (subStr.size() != 0)     //gets rid of empty strings
                    count(subStr);
                j = i+1;
            } else if (i == (len - 1)) {
                if (j == 0)     //if no spaces were found
                    count(str);
                else {          //if last word in string
                    subStr = str.substr(j, i-j+1);
                    if (subStr.size() != 0)     //gets rid of empty strings
                        count(subStr);
                }
            }
        }
    }

    //increment count for word w
    void count(std::string &w) {
        bool counted = false;

        //looks for std::string w in list str
        for (int i = 0; i < size; i++)  {
            if (w.compare(str_list[i]) == 0)  {
                str_count[i] = str_count[i] + 1;
                counted = true;
                break;
            }
        }

        //if std::string w could not be found, add w to list
        if (!counted) {
            str_list.push_back(w);
            str_count[size] = 1;
            size++;
        }
    }//count

    //compares two std::strings and finds the lexicographically smallest
    bool lexSmallCompare(std::string a, std::string b) {
        int size1 = (int) a.size(), size2 = (int) b.size(), ord1 = 0, ord2 = 0;

        if (size1 != size2)
            return (size1 < size2);

        for (int i = 0; i < size1; i++) {
            ord1 += a[i];
        }
        for (int j = 0; j < size2; j++)
            ord2 += b[j];
        return (ord1 < ord2);
    }//lexSmall

    //sorts str_list with decreasing count values, then the identical counts
    //arranged lexicographically smallest
    void lexSort() {
        int max = 0, index = 0, tmp;

        //order according count
        while (index < (size - 1)) {
            //search for index with highest count
            for (int i = index + 1; i < size; i++) {
                if (str_count[max] < str_count[i])
                    max = i;
            }

            //swap elements and count values
            str_list[max].swap(str_list[index]);
            tmp = str_count[max];
            str_count[max] = str_count[index];
            str_count[index] = tmp;
            index++;
            max = index;
        }

        int lexSmall, startIndex = 0, endIndex, range;

        //order identical counts lexicographically, smaller word first
        while(true) {

            index = startIndex;
            range = 1;

            while(true) {       //find the number of identical counts
                if(str_count[index] == str_count[index+1]) {
                    range++;
                    index++;
                }
                else
                    break;
            }

            if (range == 1) {   //if no identical counts found
                if((startIndex+1) >= size)
                    break;
                startIndex++;
                continue;
            }

            //lexSmall: holds index of lexicographically smallest word
            //startIndex: index of first value of identical count value
            //endIndex: (index + 1) of last value of identical count value
            //range: number of values with identical count
            lexSmall = startIndex;
            endIndex = startIndex + range;
            while (startIndex < endIndex) {
                for (int i = startIndex + 1; i < endIndex; i++) {
                    if( lexSmallCompare(str_list[i], str_list[lexSmall]) )
                        lexSmall = i;
                }

                //swap elements and count values
                str_list[lexSmall].swap(str_list[startIndex]);
                tmp = str_count[lexSmall];
                str_count[lexSmall] = str_count[startIndex];
                str_count[startIndex] = tmp;
                startIndex++;
                lexSmall = startIndex;
            }

            if(endIndex == size)    //exit loop
                break;
            startIndex = endIndex;
        }
    }//LexSort

    //print histogram in non-increasing count order to stdout
    void print() {
        lexSort();     // sort vector before printing
        cout << "Output:" << endl;
        for (int i = 0; i < size; i++) {
            std::cout << str_list[i] << " " << str_count[i] << std::endl;
        }
    }//print

private:
    std::vector<std::string> str_list;
    int* str_count = (int*) malloc(MAX * sizeof(int));
    int size;
};
