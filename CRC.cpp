#include<bits/stdc++.h>
using namespace std;
#define ll long long
class CRC {
public:
  string xor_operation(string s1, string s2) {
    ll len = s1.size();
    string ans = "";
    for (ll i = 1; i < len; ++i)  ans += (s1[i] == s2[i] ? '0' : '1');
    return ans;
  }
  string Division_of_Binary_no(string divident, string divisor) {
    ll len1 = divident.size(), len2 = divisor.size();
    string str = divident.substr(0, len2 - 1);
    for (ll i = len2 - 1; i < len1; ++i) {
      str += divident[i];
      str = (str[0] == '0' ? str.substr(1, str.size()) : xor_operation(str, divisor));
    }
    return str;
  }
  string Sender(string data, string key) {
    string str_appended = "";
    for (ll i = 0 ; i < key.size() - 1; ++i) str_appended += '0';
    cout << " Data Send by Sender : " << endl;
    cout << " | " << " data " << "    & " << " CRC     |" << endl;
    cout << " | " << data << "    " << Division_of_Binary_no(data + str_appended, key) << "     |" << endl;
    return Division_of_Binary_no(data + str_appended, key);
  }
  bool Receiver(string data, string key, string crc) {
    cout << " Data Receive by Receiver : " << endl;
    cout << " | " << " data " << "    & " << " CRC     |" << endl;
    cout << " | " << data << "    " << crc << "     |" << endl;
    string remai = Division_of_Binary_no(data + crc , key);
    for (ll i = 0; i < remai.size(); ++i) if (remai[i] != '0') return false;
    return true;
  }
};
int main() {
  CRC cn;
  string data, key;
  cin >> data >> key;  // data = "100000001" key = "1101";
  string crc = cn.Sender(data, key);
  char y;
  cout<<endl;
  cout << "Do you want to create the error in data(y/n) \n";
  cin >> y;
  if (y == 'y' || y == 'Y') {
    cout << "Enter the bit num to flip \n";
    cout << "(index should be less than " << data.size() - 1 << " )\n";
    ll n;
    cin >> n;
    data[n] = (data[n] == '0' ? '1' : '0');
  }
  cout<<endl;
  if (cn.Receiver(data, key, crc)) cout << "Correct data Received \n";
  else cout << "Data has an error\n";
}
