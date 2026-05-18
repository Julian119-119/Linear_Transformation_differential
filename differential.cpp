#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class polynomial {
private:
    vector<int> cofficientArr;
public:
    polynomial() {
        cofficientArr.reserve(16);
    }
    polynomial(string str) {
        stringstream ss(str);
        string token;
        while (ss >> token) {
            if (!isdigit(token[0])) std::runtime_error("input has invalid token");
            cofficientArr.push_back(stoi(token));
        }
    }
    string toString() {
        string ans;
        for (int i = 0; i < cofficientArr.size(); i++) {
            if (i == 0 && cofficientArr[i] != 0)
                ans += to_string(cofficientArr[i]) + "+";
            else if (i == 1 && cofficientArr[i] != 0)
                ans += to_string(cofficientArr[i]) + "x+";
            else if (cofficientArr[i] != 0)
                ans += to_string(cofficientArr[i]) + "x^" + to_string(i) + "+";
        }
        if (!ans.empty())
            ans.pop_back();

        return ans;
    }
    void differential() {
        /* 建造 transformation matrix */
        vector<int> transMatrix;
        for (int row = 0; row < cofficientArr.size()-1; row++) {
            for (int col = 0; col < cofficientArr.size(); col++) {
                if (row+1 == col) {
                    transMatrix.push_back(row+1);
                } else {
                    transMatrix.push_back(0);
                }
            }
        }

        /* 印出 transformation matrix */
        cout << "\ntransformation matrix is" << endl;
        for (int row = 0; row < cofficientArr.size()-1; row++) {
            cout << '|';
            for (int col = 0; col < cofficientArr.size(); col++) {
                int idx = row * cofficientArr.size() + col;
                cout << transMatrix[idx] << ' ';
            }
            cout << '|' << endl;
        }
        cout << endl;

        /* 進行矩陣乘法 */
        vector<int> afterDif;
        for (int row = 0; row < cofficientArr.size()-1; row++) {
            int dotSum = 0;
            for (int col = 0; col < cofficientArr.size(); col++) {
                int oneDArrIdx = row * (cofficientArr.size()) + col;
                dotSum += transMatrix[oneDArrIdx] * cofficientArr[col];
            }
            afterDif.push_back(dotSum);
        }

        cofficientArr = afterDif;
    }
};

int main() {
    polynomial* poly1 = new polynomial("1 0 0 0 0 0 0 0 3 8");
    cout << poly1->toString() << endl;

    poly1->differential();
    cout << "after differentiate: " << poly1->toString() << endl;
    return 0;
}