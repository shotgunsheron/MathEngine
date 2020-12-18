#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>
#include <bits/stdc++.h> 
#include <fstream>
#include <string>

//my computer science/math engine.
using namespace std;
int main();
class neuralNet {
    public:
    class firstAttempt {

        public:
        int isSubstring(string s1, string s2)
        {
            int M = s1.length();
            int N = s2.length();
 
    /* A loop to sort array one by one */
            for (int i = 0; i <= N - M; i++) {
                int j;
 
        /* For current index i, check for
 pattern match */
            for (j = 0; j < M; j++)
                if (s2[i + j] != s1[j])
                break;
 
            if (j == M)
                return i;
            }
 
            return -1;
        }
        void quit() {
            main();
        }
        int process(string inputvar) {
            string input[] = {" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ",
            " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ",
            " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ",
            " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "};
           
            for(int d =0;d <inputvar.length();d ++) {
                input[d] = inputvar[d];
            }
            string phrases[] = {"hello", "go", "it", "fit", "bit", "yell"};
            string questionPhrases[] = {"what", "?", "how", "when"};
            string endingPhrases[] = {".", "?", "!", "...", "!!!", "???", "??", "?"};
            int pLen = sizeof(phrases);
            int qLen = sizeof(questionPhrases);
            int eLen = sizeof(endingPhrases);

            for (int i = 0; i < sizeof(input); i++) {
                for (int x = 0; x < qLen; x++) {
                    if (input[x] == questionPhrases[x]) {
                        cout << "The type is: " << "question" << "\n";
                        quit();
                    } 
                }
            }
            return 0;
        }

        void mainFnc() {

            string input;
            cout << "Enter a sentence! " << "\n";
            cin >> input;
            string type;
            process(input);
        }
        
    };
    
};

class arithmetic {
    public:
        class squareRoot {
            public:
            int mySqrt(int x) 
            { 
                // Base cases 
                if (x == 0 || x == 1) 
                return x; 
            
                // Staring from 1, try all numbers until 
                // i*i is greater than or equal to x. 
                int i = 1, result = 1; 
                while (result <= x) 
                { 
                i++; 
                result = i * i; 
                } 
                return i-1; 
            } 
            int trigger() {
                int input;
                std::cout << "Enter a number to be square rooted(Rounded to nearest square root): " << "\n";
                cin >> input;
                std::cout << mySqrt(input) << "\n";
                return 0;
            }            
        };
        class addition {
            public:
            void additionServ() {
                int num;
                std::cout << "How many numbers? " << endl;
                std::cin >> num;
                double nums[num] = {};
                double currentNum;


                for (int i =0; i < num; i++) {
                    std::cout << "Enter number " << i+1 << endl;
                    std::cin >> currentNum;
                    nums[i] = currentNum;
                }

                double sum = 0;
                for(auto& numb : nums)
                    sum += numb;
                std::cout << "Sum is " << sum << "\n";
            }
        };
        class subtraction {
            public:
            void subtractionServ() {
                int num;
                std::cout << "How many numbers? " << endl;
                std::cin >> num;
                double nums[num] = {};
                double currentNum;

                for (int i =0; i < num; i++) {
                    std::cout << "Enter number " << i+1 << endl;
                    std::cin >> currentNum;
                    nums[i] = currentNum;
                }

                double diff = nums[0];
                for (int i = 0; i < num-1; i++) {
                    diff = diff-nums[i+1];
                }
                std::cout << "Difference is " << diff << "\n";
            }
        };        
        class multiplication {
            public:
            void multiplicationServ() {
                int num;
                std::cout << "How many numbers? " << endl;
                std::cin >> num;
                double nums[num] = {};
                double currentNum;

                for (int i =0; i < num; i++) {
                    std::cout << "Enter number " << i+1 << endl;
                    std::cin >> currentNum;
                    nums[i] = currentNum;
                }

                double prod =1;
                for(auto& numb : nums)
                    prod *= numb;
                std::cout << "Product is " << prod << "\n";
            }            
        };
        class division {
            public:
            void divisionServ() {
                int num;
                std::cout << "How many numbers? " << endl;
                std::cin >> num;
                if (num > 2) {
                    std::cout << "Only 2 numbers please!";
                    divisionServ();
                }
                double nums[num] = {};
                double currentNum;

                for (int i =0; i < num; i++) {
                    std::cout << "Enter number " << i+1 << endl;
                    std::cin >> currentNum;
                    nums[i] = currentNum;
                }

                double quo =1;
                quo = nums[0];
                nums[0] = 1;
                for(auto& numb : nums)
                    quo /= numb;
                std::cout << "Quotient is " << quo << "\n";
            }            
        };        
        class arithSeq {
            public:
            void mainF() {
                long int ROC;
                long int FN;
                long int N;
                std::cout << "Enter the rate of change: " << "\n";
                cin >> ROC;
                std::cout << "Enter the first number in the sequence: " << "\n";
                cin >> FN;
                std::cout << "Enter the number of the term you want: " << "\n";
                cin >> N;
                long int VAL = FN + N*ROC + ROC*-1;
                std::cout << "The " << N << "'d/'nd/'th number in the arithmetic sequence is: "<< VAL  << "\n";
                std::cout << "The equation is: a_" << N << " = " << FN << "+" << "(" << N << "-1" << ")" << "*" << ROC << "\n";

            }
            int trigger() {
                mainF();
                return 0;
            }
        };
};

class physics {
    public:
        class predict {
            public:
            void calculate(float speed, float distance) {
                float time = distance/speed;
                std::cout << "Time in hours to reach destination: " << time << "\n";
            } 
            int trigger() {
                float spdeed;
                float distdance;
                std::cout << "Enter speed(mph): ";
                std::cin >> spdeed;
                std::cout << "Enter distance(miles): ";
                std::cin >> distdance;
                calculate(spdeed, distdance);
                return 0;
            }
        };


};

class searches {
    public:
        class largest {
            public:
            void calculate() {
                int i, n;
                float arr[100];

                cout << "Enter total number of elements(up to 100): ";
                cin >> n;
                cout << endl;

                // Store number entered by the user
                for(i = 0; i < n; ++i)
                {
                cout << "Enter Number " << i + 1 << " : ";
                cin >> arr[i];
                }

                // Loop to store largest number to arr[0]
                for(i = 1;i < n; ++i)
                {
                // Change < to > if you want to find the smallest element
                if(arr[0] < arr[i])
                    arr[0] = arr[i];
                }
                cout << "Largest element = " << arr[0] << "\n";
                
            }
            int trigger() {
                calculate();
                return 0;
            }
        };
        class generalSearch {
            public:
            void Crack(string num, vector<char> Chars) 
            { 
                cout<< "NUMBER TO CRACK: " << num << endl; 
                int n = Chars.size(); 
                int i = 0; 
            while(true) 
                { 
                    i++; 
                    int N = 1; 
                    for(int j = 0; j < i; j++) N*=n; 
                    for(int j = 0; j < N; j++) 
                    { 
                        int K = 1; 
                        string crack = ""; 
                        for(int k = 0;k < i; k++) 
                        { 
                            crack += Chars[j / K % n]; 
                            
                            K *= n; 
                        } 
                        cout << "Testing Number: "<< crack << " " << "against " << num << endl; 
                        if(num.compare(crack) == 0) { 
                            cout<< "Cracked number: "<< crack << endl; 
                        return; 
                        } 
                    } 
                } 
            } 
            int trigger() 
            { 
                vector<char> Chars; 
                cout << "Enter a number! (1-4 digits recommended for speed.)" << "\n";
                string inputed;
                cin >> inputed;

                for(char c = '0'; c<='z'; c++){ 
                if( isalpha(c) || isdigit(c) )Chars.push_back(c); 
                }

                    Crack(inputed, Chars);  
                    return 0;       

            }             
        };
        class numSearch {
            public:
            void Crack(string num, vector<char> Chars) 
            { 
                cout<< "NUMBER TO CRACK: " << num << endl; 
                int n = Chars.size(); 
                int i = 0; 
                while(true) 
                { 
                    i++; 
                    int N = 1; 
                    for(int j = 0; j < i; j++) N*=n; 
                    for(int j = 0; j < N; j++) 
                    { 
                        int K = 1; 
                        string crack = ""; 
                        for(int k = 0;k < i; k++) 
                        { 
                            crack += Chars[j / K % n]; 
                            
                            K *= n; 
                        } 
                        cout << "Testing Number: "<< crack << " " << "against " << num << endl; 
                        if(num.compare(crack) == 0) { 
                            cout<< "Cracked number: "<< crack << endl; 
                        return; 
                        } 
                    } 
                } 
            } 
            int trigger() 
            { 
                vector<char> Chars; 
                cout << "Enter a number! (1-4 digits recommended for speed.)" << "\n";
                string inputed;
                cin >> inputed;

                for(char c = '0'; c<='9'; c++){ 
                if( isalpha(c) || isdigit(c) )Chars.push_back(c); 
                }

                    Crack(inputed, Chars);  
                    return 0;       

            }             
        };
        class stringSearch {
            public:
            void Crack(string word, vector<char> Chars) 
            { 
                cout<< "STRING TO CRACK: " << word << endl; 
                int n = Chars.size(); 
                int i = 0; 
                while(true) 
                { 
                    i++; 
                    int N = 1; 
                    for(int j = 0; j < i; j++) N*=n; 
                    for(int j = 0; j < N; j++) 
                    { 
                        int K = 1; 
                        string crack = ""; 
                        for(int k = 0;k < i; k++) 
                        { 
                            crack += Chars[j / K % n]; 
                            K *= n; 
                        } 
                        cout << "Testing string: "<< crack << " " << "against " << word << endl; 
                        if(word.compare(crack) == 0) { 
                            cout<< "Cracked string: "<< crack << endl; 
                        return; 
                        } 
                    } 
                } 
            } 
            int trigger() 
            { 
                vector<char> Chars; 
                cout << "Enter a string or word! (1-4 characters recommended for speed.)" << "\n";
                string inputed;
                cin >> inputed;
                for(char c = 'a'; c<='z'; c++){ 
                    if( isalpha(c) || isdigit(c) )Chars.push_back(c); 
                    } 
                    Crack(inputed, Chars); 
                    return 0;
            } 
        };
};



int main() {

    //initializing objects:
    neuralNet::firstAttempt firstAttemptCall;
    arithmetic::arithSeq arithSeqCall;
    arithmetic::subtraction subtractionCall;
    arithmetic::addition additionCall;
    arithmetic::multiplication multiplicationCall;
    arithmetic::division divisionCall;
    arithmetic::squareRoot squareRootCall;
    searches::generalSearch generalSearchCall;
    searches::numSearch numSearchCall;
    searches::stringSearch stringSearchCall;
    physics::predict predictCall;
    searches::largest largestCall;

    //getting input for operation:
    int input;
    std::cout << "Press 1 for Addition, 2 for Subtraction, 3 for Multiplication, 4 for Division, 5 for Convex Hull(in dev), 6 for General Search, 7 for Number Search, 8 for String Search, 9 for square root, 10 for calculating time from distance and speed, 11 to calculate largest element in a list, 12 to find NTH term in arithmetic sequence, 13 for string analyzer: " << "\n";
    std::cin >> input;
    

    //controlling flow of program based on input:
    switch(input) {
        case 1:
            additionCall.additionServ();
            break;

        case 2:
            subtractionCall.subtractionServ();
            break;
        case 3:
            multiplicationCall.multiplicationServ();
            break;
        case 4:
            divisionCall.divisionServ();
            break;
        case 5:
            //convexHullCall.call();    
            break;
        case 6:
            generalSearchCall.trigger();
        case 7:
            numSearchCall.trigger();
        case 8:
            stringSearchCall.trigger();
        case 9:
            squareRootCall.trigger();
        case 10:
            predictCall.trigger();
        case 11:
            largestCall.trigger();
        case 12:
            arithSeqCall.trigger();
        case 13:
            firstAttemptCall.mainFnc();
    }
    //std::cout << method.additionData();
}