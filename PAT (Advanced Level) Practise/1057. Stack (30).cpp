/**
* 分析：因为stl的stack不方便排序比大小，因此用了一个vector模拟栈
*       但是只得了17分，三个点TLE，事实证明考场上不会的题直接暴力一发也是有点分的
*       参照晴神标程，因为数据上界为10^5，可用分块思想解题
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
const int maxb = sqrt(100001); //块内元素个数 即根号N 向下取整

stack<int> st;
int block[maxb], h[maxn]; //block[i]:第i块中的元素个数  x/maxb即x应该在的块号  h[x]:数字x的存在个数

int main() {
    int n, k;
    string s;
    cin >> n;
    while(n--) {
        cin >> s;
        if(s == "Push") {
            cin >> k;
            st.push(k);
            h[k]++;
            block[k / maxb]++;
        } else if(s == "Pop") {
            if(!st.empty()) {
                k = st.top();
                cout << k << endl;
                st.pop();
                h[k]--;
                block[k / maxb]--;
            } else {
                cout << "Invalid" << endl;
            }
        } else if(s == "PeekMedian") {
            if(!st.empty()) {
                int t = st.size();
                if(t % 2 == 0)
                    t /= 2;
                else
                    t = (t + 1) / 2;
                int sum = 0, numb = 0;
                while(sum + block[numb] < t) { //找到第t大的数所在块号
                    sum += block[numb++];
                }
                int num = maxb * numb; //找到所在块的第一个数
                while(sum + h[num] < t) {
                    sum += h[num++];
                }
                cout << num << endl;
            } else {
                cout << "Invalid" << endl;
            }

        }
    }
    return 0;
}







//vector<int> st,temp; //一个用来模拟栈，一个用来排序输出
//
//int main() {
//	int n,k,top;
//	string s;
//	cin>>n;
//	while(n--) {
//		cin>>s;
//		if(s=="Push") {
//			cin>>k;
//			st.push_back(k);
//		} else if(s=="Pop") {
//			if(st.size()!=0) {
//				auto it = st.end()-1;
//				cout<<*it<<endl;
//				st.erase(it);
//			} else
//				cout<<"Invalid"<<endl;
//		} else if(s=="PeekMedian") {
//			if(st.size()!=0) {
//				temp=st;
//				int t=temp.size();
//				if(t%2==0)
//					t/=2;
//				else
//					t=(t+1)/2;
//				sort(temp.begin(),temp.end());
//				cout<<temp[t-1]<<endl;
//			} else
//				cout<<"Invalid"<<endl;
//		}
//	}
//	return 0;
//}
