#include<iostream>
#include<fstream>
#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	ifstream inFile("input.txt");
	if(!inFile.is_open()){
		cout<<"open failed"<<endl;
		return -1;
	}
	unordered_map<string,int>wordcount;
	string word;
	while(inFile>>word){
		 for (char& c : word) {
			 c = tolower(c); 
		 }
		while (!word.empty() && ispunct(word.back())) {
			word.pop_back();
		}
		if(word.empty()) continue; 
		wordcount[word]++;
	}
	/*while(inFile>>word){
		cout<<word<<endl;
	}*/
	inFile.close();
	ofstream outFile("result.txt");
	if(!outFile.is_open()){
		cout<<"ofs failed"<<endl;
		return -1;
	}
	cout << "一共有 " << wordcount.size() << " 种单词" << endl;
	cout << "--- 开始排序 ---" << endl;
	vector<pair<string, int>> vec(wordcount.begin(), wordcount.end());
	sort(vec.begin(), vec.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
		return a.second > b.second; 
	});
	 cout << "--- 词频 Top 10 ---" << endl;
	int count = 0;
	for (const auto& pair : vec) {
		cout << count + 1 << ". " << pair.first << " : " << pair.second << "次" << endl;
		outFile << count + 1 << ". " << pair.first << " : " << pair.second << "次\n";
		count++;
		if (count == 10) break;}
	outFile.close();
	return 0;
}
