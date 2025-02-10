// LeetCode.cpp : Defines the entry point for the console application.
//

#include "LeetCode.h"
#include <condition_variable>
#include <climits>

mutex m;
condition_variable cond;
int loop = 10;
int flag = 0;
int flag0 = 10;//条件

void fun(int num) {
    for (int i = 0; i<5; i++) {
        unique_lock<mutex> lk(m);//A unique lock is an object that manages a mutex object with unique ownership in both states: locked and unlocked.
        while (flag0 != num)
            cond.wait(lk);//在调用wait时会执行lk.unlock()
        for (int j = 0; j<num; j++)
            cout << j << " ";
        cout << endl;
        flag0 = (num == 10) ? 20 : 10;
        cond.notify_one();//被阻塞的线程唤醒后lk.lock()恢复在调用wait前的状态
    }
}

int lt_test()
{
    printf("Hello!\n");

    Solution tempS;

    //Debug
    minCut("aab");


    cout << "\r\n the end\n";
    return 0;
}

template<class T> 
T getmax(T a, T b) {
	T result;
	result = a > b ? a : b;
	return result;
};

int testThread(int i) {
	for (; i < 10; i++);
	return i;
};

static int testofstatic2 = 0;

template<class T>
T getmin(T a, T b) {
	return a;
};

void printStr()
{
	int normal = 0;
	static int stat = 0; //this is a static local var  
	cout << "\n normal: " << normal << "       static: " << stat;
	normal++;
	stat++;
};

// test of memory
char* testofmemory = reinterpret_cast<char*> (0x00100000);

void func(int id)
{
	for (int i = 0; i < loop; ++i)
	{
		unique_lock<mutex> lk(m);
		while (flag != id)
			cond.wait(lk);
		cout << static_cast<char>('A' + id) << " ";
		flag = (flag + 1) % 3;
		cond.notify_all();
	}
}










void old_practice() {
    Solution tempS;

    const int clen = 100;
    char c[clen];

    /*
	cout << i;

	//int, str;
	for (i = 0; i < 10; i++)
		cout << "\r\n the num is: " << i + pow(10, i) << "\r\n the str is: " << to_string(i + pow(10, i));

	// 383;
	cout << "\r\n" << "Ransom solution: " << tempS.CanConstruct(str1, str2);

	// 387;
	for (i = 0; i < 3; i++)
		cout << "\r\nthe first char position is: " << tempS.FirstUniqChar(str[i]);

	// 389
	cout << "\r\n the difference is: " << tempS.findTheDifference(str[0], str[1]);

	//400
	cout << "\r\n the digit is: " << tempS.findNthDigit(187);

	//401
//	tempS.readBinaryWatch(3);

	//405
	cout << "\r\n the hex is: " << tempS.toHex(-1);

	//409
	string s409 = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
//	string s409 = "abccccdd";
	cout << "\r\n The longest palindrome is: " << tempS.longestPalindrome(s409);

	//326
	cout << "\r\n isPowerOfThree: " << tempS.isPowerOfThree(243);

	//283
	vector<int> v283 = { 0,0,1 };
	tempS.moveZeroes(v283);
	cout << "\r\n the final vector is: ";
	for (auto it = v283.begin(); it != v283.end(); it++)
		cout << *it << ",";

	//290
	string s290 = "abcd";// "Wooo.. This is a test string! -> Thanks.";
	string subStr290;

	subStr290 = s290.substr(0, s290.find(" "));
	cout << "\r\n the sub str of s290 is :"<< subStr290;
//	s290.erase(s290.begin(), s290.begin() + s290.find(" "));
	cout << "\r\n the erased str is :" << s290;

	string pattern290 = "abbac";
	string str290 = "dog cat cat dog ";
	cout << "\r\n the pattern is :" << tempS.wordPattern(pattern290, str290);

	//299
	string s1_299 = "011", s2_299 = "110";
	string s = "ABCDEFG";
	s.erase(2,1);
	cout << "\r\n S:" << s;

	cout << "\r\n bulls and cows: " << tempS.getHint(s1_299, s2_299);

	//236
	tempS.l236();

	//7
	cout << "\r\n the reverted int is: " << tempS.reverse(1534236469);

	//8
	cout << "\r\n length of int: " << sizeof(int);
	cout << "\r\n the atoi lib: " << atoi("-2");

	//13
	map<char, int> m13 = { { 'I',1 }, { 'I',1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
	cout << "\r\n the inserted item position: " << (m13.insert(pair<char, int>('A', 0)).first)->first;
	for (auto it = m13.begin(); it != m13.end(); it++)
	{
		cout << "\r\n the map key is: " << it->first;
		cout << "\r\n the map value is: " << it->second;
	}

	set<char> s13 = { 'C', 'E', 'E', 'D', 'B' };
	cout << "\r\n SET";
	cout << "\r\n the first inserted item position: " << *((s13.insert('A')).first);
	for (auto it = s13.begin(); it != s13.end(); it++)
	{
		cout << "\r\n the set key is: " << *it;
	}

	//28
	string s28 = "This is a test!";
	cout << "\r\n string comparing result: " << s28.compare(0, 0, "");

	//36
	vector<vector<char>> v36 = { {'a','b'},{ 'a','b' } ,{ 'a','b' } };
	cout << "\r\n the line is: " << v36.size();
	cout << "\r\n the column is: " << v36[2].size();

	//172
	cout << "\r\n the trailing zeroes: " << tempS.trailingZeroes(1808548329);

	//204
	vector<int> v204(10);
	cout << "\r\n the size of array is: " << v204[9];
	cout << "\r\nend";

	//202
	char c202 ='7';
	char ca202[10] = "12";
	string s202 = "8 This is a test string!";
	string::size_type st202;

	s202.replace(2, 4, "that");
	cout << "\r\n" << s202;


	int i202 = stoi(ca202);
	i202 = stoi(s202, &st202, 16);
	s202 = s202.substr(st202, 20);
	i202 = stoi(ca202);

	double d202 = 9876543210;
	i202 = (int)d202;

	//198
	vector<int> v198 = { 123,42,3545,644,23426,5656,345,2,645,23,64,67,8676,234,25,27,753,3575,1 };
	tempS.rob(v198);
*/
    //190
    string s190 = "ABCD";
    rotate(s190.begin(), s190.end() - 2, s190.end());
    cout << s190;
    reverse(s190.begin(), s190.end());
    cout << "\r\n" << s190;

    bitset<32> b190(4);

    s190 = b190.to_string();
    cout << "\r\n" << b190;
    cout << "\r\n string: " << s190;
    reverse(s190.begin(), s190.end());
    cout << "\r\n string: " << s190;

    //169
    vector<int> v169 = { 1 };
    tempS.majorityElement(v169);

    //119
    tempS.getRow(6);

    //118
    tempS.generate(3);

    //66
    vector<int> i66(10);

    //67
    string s67 = "It's a test.";
    string t67 = "This is also one test!!!";

    s67.swap(t67);

    cout << "\r\n First string: " << s67 << "The size is: " << s67.size();
    cout << "\r\n Second string: " << t67 << "The size is: " << t67.size();
    string a67 = "10111";
    string b67 = "10";
    tempS.addBinary(a67, b67);

    //100. Same Tree
    Solution::TreeNode t100(1000);
    Solution::TreeNode t200(100, 100);
    cout << "\r\n The tree node value is: " << tempS.GlobalTreeNode.val;
    cout << "\r\n The tree node value is: " << t100.val;
    cout << "\r\n The tree node value is: " << t200.val;

    //107. Binary Tree Level Order Traversal II;

    string s107 = "1234567890";
    cout << "\n part of the string: " << string(s107.begin() + 5, s107.end());
//	cout << "\n override +: " << t200 tempS.+ t100;
    vector<vector<int>> v107 = { {1,2,3},{4,5,6} };
    cout << "\n rbegin() of vector<vector<int>> { {1,2,3},{4,5,6} }: " << (*v107.rbegin())[0] << "," << (*v107.rbegin())[1] << "," << (*v107.rbegin())[2];
    vector<int> v107_1 = { 1,2,3 };

    ////ERROR!!!!!!!!!!!!!!!
//	v107_1.assign(v107_1.rbegin(), v107_1.rend());

    //136. Single Number
    vector<int> v136 = { -1 };
    tempS.singleNumber(v136);

    //121. Best Time to Buy and Sell Stock
    vector<int> v121 = { 7,1,5,3,6,4 };
    tempS.maxProfit(v121);

    //123. Best Time to Buy and Sell Stock III
    vector<int> v123 = { 2,1,2,0,1 };
    vector<int> testV(0);
    tempS.maxProfit123(v123);

    //376
    vector<int> v376 = { 1,7,4,9,2,5 };
    tempS.wiggleMaxLength376(v376);

    //113. Path Sum II
    vector<int> v113 = { 1 };
    tempS.testVector(v113);
    cout << "\n test vector 1: " << v113.back();
    tempS.testVector(v113, 0);
    cout << "\n test vector 2: " << v113.back();

    //416. Partition Equal Subset Sum
    vector<int> v416 = { 1, 2, 3};
    tempS.canPartition(v416);

    vector<int> v416_1(2);

    v416_1 = { 0 };

    //415. Add Strings
    string s415_1 = "0";
    string s415_2 = "0";
    tempS.addStrings(s415_1, s415_2);

    //vmware
    map<string, int> m_v = { {"354", 354}, {"353", 353}, {"21", 21}, {"20", 20}, {"def", 456}, {"dd", 44} };
    cout << "\n map sequences: \n";
    for (auto it = m_v.begin(); it != m_v.end(); it++)
        cout << it->second << ", ";

    string vmware_s1 = "11011001011000111";
    string vmware_s2 = "111111111111111";
    string vmware_s3 = "10";
    string vmware_s4 = "0";
    pair<int, int> res;
    res = tempS.VMWareFlip(vmware_s1);
    cout << "\n VMWare flip: \n" << vmware_s1 << ": " << tempS.VMWareFlip(vmware_s1).first << tempS.VMWareFlip(vmware_s1).second;
    res = tempS.VMWareFlip(vmware_s2);
    cout <<"\n" << vmware_s2 <<": "<< tempS.VMWareFlip(vmware_s2).first << tempS.VMWareFlip(vmware_s2).second;
    res = tempS.VMWareFlip(vmware_s3);
    cout << "\n" << vmware_s3 << ": " << tempS.VMWareFlip(vmware_s3).first << tempS.VMWareFlip(vmware_s3).second;
    res = tempS.VMWareFlip(vmware_s4);
    cout << "\n" << vmware_s4 << ": " << tempS.VMWareFlip(vmware_s4).first << tempS.VMWareFlip(vmware_s4).second;

    ////315. Count of Smaller Numbers After Self
    vector<int> v315 = { 5,2,6,1 };
    tempS.countSmaller(v315);

    ////170. Two Sum III - Data structure design
    map<int, int> maps170;
    for (int i = 0; i < 5; i++)
    {
        maps170[i]++;
        maps170[i]++;
    }

    //167. Two Sum II - Input array is sorted
    vector<int> v167 = { 0,0,3,4 };
    tempS.twoSum(v167, 0);

    //1 Two Sum
    vector<int> v_1 = { 3, 2, 4 };
    tempS.twoSum_I(v_1, 6);

    //2. Add Two Numbers
    Solution::ListNode* l1 = new Solution::ListNode(9);
    Solution::ListNode* l2 = new Solution::ListNode(1);

    l1->next = new Solution::ListNode(8);
//	l1->next->next = new Solution::ListNode(3);
//	l2->next = new Solution::ListNode(6);
//	l2->next->next = new Solution::ListNode(4);
    tempS.addTwoNumbers(l1, l2);

    //151. Reverse Words in a String
    string s_151 = " ";
    tempS.reverseWords(s_151);

    string s151 = "   a   b  c d   e               ";

    while (s151.back() == ' ')
        s151.erase(s151.size() - 1, 1);

    tempS.reverseWords(s151);

    ////414. Third Maximum Number
    set<int> s414;
    for (int i = 1; i <= 8; i++)
        s414.insert(i * 10);
    auto itLow = s414.lower_bound(25);
    auto itUpper = s414.upper_bound(75);

    cout << "\n lower_bound: " << *itLow;
    cout << "\n upper_bound: " << *itUpper;

    ////3. Longest Substring Without Repeating Characters
    // string s3 = "abcabcbb";
    // tempS.lengthOfLongestSubstring(s3);

    //15. 3Sum
    // vector<int> v15 = { -1,0,1,2,-1,-4 };
    // tempS.threeSum(v15);

    //5. Longest Palindromic Substring
    string s5 = "";
    string s5_1 = s5.substr(0, 1);


    //433. Minimum Genetic Mutation
    string s433_1 = "AACCGGTT";
    string s433_2 = "AAACGGTA";
    vector<string> v433 = { "AACCGGTA", "AACCGCTA", "AAACGGTA" };
    cout << "\n the minimum mutations is: " << tempS.minMutation(s433_1, s433_2, v433);

    int size = (int)v433.size();
    auto it433 = v433.begin();
    for (int i = 0; i < size; i++)
        it433 = v433.erase(it433);

    vector<bool> v433_1(100);

    ////432. All O`one Data Structure
    list<Solution::bucket> s432 = { {1, {"A1"}}, {2,{ "A2" }}, {3,{ "B1" }}, {4,{ "B2" }} };
    auto it432 = s432.begin();
    cout << "\n the first: " << it432->val << "  the second: " << (it432++)->val;

    tempS.inc("a");
    tempS.inc("b");
    tempS.inc("b");
    tempS.inc("b");

//	cout << "\n get max key:" << tempS.getMaxKey();
//	cout << "\n get min key:" << tempS.getMinKey();

    tempS.inc("b");
//	tempS.inc("code");
//	tempS.inc("leet");

    tempS.dec("b");
    tempS.dec("b");
//	tempS.inc("leet");
//	tempS.inc("code");
//	tempS.inc("code");
    cout << "\n get max key:" << tempS.getMaxKey();
    cout << "\n get min key:" << tempS.getMinKey();

    //348. Design Tic-Tac-Toe
    tempS.TicTacToe(3);
    tempS.move(1, 1, 2);
    tempS.move(0, 0, 2);
    tempS.move(2, 0, 2);


    ////186. Reverse Words in a String II
    string s = "a b";
    tempS.reverseWords2(s);

    //148. Sort List
    int i148 = INT_MAX;
    int j148 = INT_MIN;

    //200. Number of Islands
    vector<vector<char>> v200 = { {'1','1','1'}, { '0','1','0' }, { '1','1','1' } };
    tempS.numIslands(v200);

    //218. The Skyline Problem
    vector<pair<int, int>> v218 = { pair<int,int>(3,5), pair<int,int>(3,-5) , pair<int,int>(2,6)};
    sort(v218.begin(), v218.end());

    cout << "\n max: " << i148 << "\n min: " << j148;

    //297. Serialize and Deserialize Binary Tree
    string s297 = "1 # # ";
    tempS.deserialize(s297);
    //tempS.deserialize(tempS.serialize(tempS.deserialize(s297)));

    //268. Missing Number
    vector<int> v268 = { 0,1 };
    tempS.missingNumber(v268);

    //238. Product of Array Except Self
    vector<int> v238(3);
//	v238 = vector<int>{};

    //73. Set Matrix Zeroes
    vector<vector<int>> v73 = { {1} };
    tempS.setZeroes(v73);

    //98. Validate Binary Search Tree
    Solution::TreeNode* t98 = nullptr;
    tempS.isValidBST(t98);

    //208. Implement Trie (Prefix Tree)
    bool b208;
    Trie trie;
    trie.insert("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    b208 = trie.search("a");

    //Test of pointer to pointer
    int i208[3] = { 1,2,3 };
    int* ptrInt = i208;
    cout << "\n Int pointer: " << *ptrInt << *(ptrInt + 1) << *(ptrInt + 2);
    int** ptrPtrInt = new int*[3];
    ptrPtrInt[0] = i208;
    cout << "\n Int pointer: " << *ptrPtrInt[0] << *(ptrPtrInt[0] + 1) << *(ptrPtrInt[0] + 2);
    tempS.PointertoPointerTest();

    // 23. Merge k Sorted Lists
    tempS.mergeKLists();

    //270. Closest Binary Search Tree Value
    int i270[2] = { 3, 4 };
    double f270 = 3.285714;

    double f270_1 = abs(i270[0] - f270);
    double f270_2 = abs(i270[1] - f270);

    ////212. Word Search II
//	vector<vector<char>> v212 = { {'o','a','a','n'}, {'e','t','a','e'}, {'i','h','k','r'}, {'i','f','l','v'} };
//	vector<string> vs212 = { "oath", "pea", "eat", "rain" };
    vector<vector<char>> v212 = {{'a','b'}, {'c','d'} };
//	vector<string> vs212 = { "ab","cb","ad","bd","ac","ca","da","bc","db","adcb","dabc","abb","acb" };
    vector<string> vs212 = { "abcd" };
    tempS.findWords(v212, vs212);

    //333. Largest BST Subtree
    pair<bool, int[3]> p333;
    p333.first = true;
    p333.second[0] = 1;
    p333.second[1] = 2;
    p333.second[2] = 3;

    //451. Sort Characters By Frequency
    string ss451 = "tree";
    tempS.frequencySort(ss451);

    map<char, int> m451;
    m451['a'] = 1;
    m451['b'] = 2;
    m451['a'] = 3;

    for (auto m : m451)
        cout << "\n451. Sort Characters By Frequency: " << " " << m.first << ", " << m.second << ", ";

    int i451 = 'a';
    string s451 = "";
    s451 += (char)i451;

    cout << "string: " << s451;

    set<int> set451;
    set451.insert(5);
    set451.insert(3);

    for(auto it = set451.begin(); it != set451.end(); it++)
        cout << "\n set: " << *it;

    auto it451 = set451.begin();


    //316. Remove Duplicate Letters
    string s316 = "bcab";
    cout << "\nRemove Duplicate Letters: " << tempS.removeDuplicateLetters(s316);

    //71. Simplify Path
    string str71 = "/";
    tempS.simplifyPath(str71);

    //165. Compare Version Numbers
    string str165_1 = "1.1", str165_2 = "1";
    tempS.compareVersion(str165_1, str165_2);

    //125. Valid Palindrome
    char ch125 = ',';
    ch125 = tolower(ch125);
    cout << "\n to lower case: " << ch125;

    string s125 = "a ba";
    tempS.isPalindrome(s125);


    ////25. Reverse Nodes in k-Group
    tempS.test25();

    //56. Merge Intervals
    tempS.test56();

    //Given a list of integers, return the first unique integer   . Ex. given [4, 8, 3, 8, 9, 4, 7, 9], return 3
    unordered_map<int, int> testMap;
    testMap[3] = 0;
    testMap[1]++;
    testMap[2]++;
    testMap[1]++;
    cout << "\n test map: " << testMap[1] << "," << testMap[2] << ", "<< testMap[3] << ",";

    // random number
    //include <time.h>
    //include <stdlib.h>

    srand((unsigned int)time(NULL));
    int random_test_0319 = rand();
    cout << "\n random number: " << rand() << ", " << rand() << ", " << rand() << ", " << rand() << ", " << rand() << ", " << rand() << ", " << rand();

    //square root of n

    cout << "\n input one integer: ";
    int testi = 10;
//	cin >> testi;
    double testd = 0.000000001;

    double xd1 = testi;
    double xd2 = 0;
    while (abs(xd1 - xd2) > testd) {
        xd2 = xd1;
        xd1 = (xd2 + testi / xd2) / 2;
    }

    cout << "\n the square root of " << testi << "  is " << xd1 << " or " << xd2 << endl;
    // test hash
    std::hash<string> testHash;
    cout << "Hash value of ABCD: " << testHash("ABCDEFGHIJKLMNOPQRSGUVWXYZ");

    int t0304 = (int)testHash("ABCDEFGHIJKLMNOPQRSGUVWXYZ");
    cout << "\n Hash value of ABCDEFGHIJKLMNOPQRSGUVWXYZ (int): " << t0304;

    long t0304l = (long)testHash("ABCDEFGHIJKLMNOPQRSGUVWXYZ");
    cout << "\n Hash value of ABCDEFGHIJKLMNOPQRSGUVWXYZ (long): " << t0304l;

    long long t0304ll = testHash("ABCDEFGHIJKLMNOPQRSGUVWXYZ");
    cout << "\n Hash value of ABCDEFGHIJKLMNOPQRSGUVWXYZ (long long):  \n" << t0304ll;

    long long t0304ll_1 = testHash("ABCDEFGHIJKLMNOPQRSGUVWXY");
    cout << "\n Hash value of ABCDEFGHIJKLMNOPQRSGUVWXY (long long):  \n" << t0304ll_1;

    long long t0304ll_2 = testHash("BCDEFGHIJKLMNOPQRSGUVWXYZ");
    cout << "\n Hash value of BCDEFGHIJKLMNOPQRSGUVWXYZ (long long):  \n" << t0304ll_2;

    long long t0304ll_3 = t0304ll_1 + testHash("Z") - testHash("A");
    cout << "\n Hash value of ABCDEFGHIJKLMNOPQRSGUVWXY - hash(A) + hash(Z)(long long):  \n" << t0304ll_3;


    t0304ll_1 = testHash("A");
    cout << "\n Hash value of A (long long):  \n" << t0304ll_1;

    t0304ll_2 = testHash("B");
    cout << "\n Hash value of B (long long):  \n" << t0304ll_2;

    t0304ll_3 = t0304ll_1 + t0304ll_2;
    cout << "\n Hash value of Hash(A) + Hash(B) (long long):  \n" << t0304ll_3;

    t0304ll_1 = testHash("AB");
    cout << "\n Hash value of AB (long long):  \n" << t0304ll_1;

    cout << "\n";

    vector<pair<int,int>> test;
    test.push_back(pair<int, int>(1, 2));

    // find the longest substr
    Trie suffixTrie;
    string longestSubStr1 = "dfadnfienngseirangjehiahegniwenaeiaeinegeiiwenagie";
    string longestSubStr2 = "dajdifanifenaifaeewenaeikienfiaenfiaefneifen";

    cout << "\n the longest substr is: " << suffixTrie.findLongestSubstr(longestSubStr1, longestSubStr2);


    //249. Group Shifted Strings
    vector<string> v249 = { "a", "ac", "bd", "adsdfsdfsd" };
    tempS.groupStrings(v249);


    //215. Kth Largest Element in an Array
//	minstd_rand0 generator((unsigned int)chrono::system_clock().now().time_since_epoch().count());
    minstd_rand generator((unsigned int)time(NULL));
    cout << "\n the random number is:" << generator() << "\n the seed is: " << (unsigned int)time(NULL);
    cout << "\n the random number is:" << generator() << "\n the seed is: " << (unsigned int)time(NULL);
    cout << "\n the random number is:" << generator() << "\n the seed is: " << (unsigned int)time(NULL);
    cout << "\n the random number is:" << generator() << "\n the seed is: " << (unsigned int)time(NULL);
    cout << "\n the random number is:" << generator() << "\n the seed is: " << (unsigned int)time(NULL);
    cout << "\n the random number is:" << generator() << "\n the seed is: " << (unsigned int)time(NULL);
    cout << "\n the random number is:" << generator() << "\n the seed is: " << (unsigned int)time(NULL);
    cout << "\n the random number is:" << generator() << "\n the seed is: " << (unsigned int)time(NULL);
    cout << "\n the random number is:" << generator() << "\n the seed is: " << (unsigned int)time(NULL);

    //191. Number of 1 Bits
    tempS.hammingWeight(56);

    //92. Reverse Linked List II
    tempS.test92();

    //function template
    int a = 1, b = 2;
    int k;
    k = getmax(a, b);
//	cout << "\n funtion tempalte: " << getmax(a, b);

    //thread
    cout << "\n \n Test of Thread \n \n";
    thread first_thread(testThread, 0);

    thread child(fun, 10);
    fun(100);
    child.join();



    thread A(func, 0);
    thread B(func, 1);
    func(2);
    cout << endl;

    A.join();
    B.join();



    //MAIL
    // under windows only
    // HINSTANCE hInstMail;
    // hInstMail = LoadLibrary(_T("MAPI32.DLL"));
    // ULONG (PASCAL *lpfnMAPISendMail) ( LHANDLE lhSession, ULONG ulUIParam, lpMapiMessage lpMessage);
    // (FARPROC&) lpfnMAPISendMail = GetProcAddress(hInstMail, "MAPISendMail");


    //Exception
    try {
        fgets(c, clen, stdin);
//		throw 100;
//		vector<int> exceptions;
//		exceptions[0] = 1;
    }
    catch (out_of_range& oor) {
        cerr << "\nError ID: " << oor.what();
    }


    //448. Find All Numbers Disappeared in an Array

    vector<int> v448 = { 4,3,2,7,8,2,3,1 };
    tempS.findDisappearedNumbers(v448);

    //460. LFU Cache Add to List
    tempS.LFUCache(2);
    tempS.set_460(1, 1);
    tempS.set_460(2, 2);
    tempS.get_460(1);
    tempS.set_460(3, 3);
    tempS.get_460(2);
    tempS.get_460(3);
    tempS.set_460(4, 4);
    tempS.get_460(1);
    tempS.get_460(3);
    tempS.get_460(4);

    //test pointer;
    Solution::ListNode *pTest = nullptr;
    pTest = new Solution::ListNode(0);
    delete pTest;

    //test to_string;
    cout << "\n to_string(41): " << to_string(41);
    char tmpChar = 0x41;
    string tmpStr = "";
    tmpStr += tmpChar + 1;
    tmpStr += 0x41;
    tmpStr += tmpStr;


    //test hash_map
//	hash_map<int, string> tmpHashMap;

    cout << "  " << tmpChar << "  " << tmpStr;

    // test vector<vector<int>>
    vector<vector<int>> test_vector;

    test_vector.resize(3, vector<int>(4));

    // test sort
    vector<int> testOfSort1 = { 5, 9, 2, 3, 1, 0, -100, 2000, 30, -1000000, 23 };
//	tempS.QuickSort(testOfSort1);
    tempS.MergeSort(testOfSort1);

    //412. Fizz Buzz Add to List
    tempS.fizzBuzz(3);

    //TEST unordered_set
    unordered_set<int> testOfUSet = { 5, 2, 1, 9, -10, -5 };
    testOfUSet.erase(testOfUSet.begin());
    testOfUSet.insert(30);
    unordered_set<int> testOfUSet1(20);

    //Test of Sudoku
    vector<vector<int>> TestOfSudoku =
            { {1, 2, 3},
              {2, 3, 1},
              {3, 2, 2} };
    bool TestOfSudoku1 = tempS.Sudoku(TestOfSudoku);

    //test of find
    list<pair<int, int>> testfindlist;
    testfindlist.push_front(pair<int, int>(1, 2));
    auto ittestfind = find(testfindlist.begin(), testfindlist.end(), pair<int, int>(1, 2));
    cout << "\ntest find in list, first: " << ittestfind->first << ", second: " << ittestfind->second;
    list<int> tmptestfind = { 1 };

    // MS OTS 02/07/2017
    set<pair<int, int>> test2717;
    pair<int, int> ref2717 = { 2,3 };
    for (int i = 0; i < 100; i++)
        test2717.insert(pair<int, int>{i, i});
    set<pair<int, int>> ans2717;
    ans2717 = tempS.ClosestKPoints(test2717, ref2717, 5);

    //test of struct
//	Solution::testofstruct teststruct;
//	teststruct.str = "test of struct";

    // test of set
    vector<string> testofset1 = { "6", "7" };

    unordered_set<string> testofset(5);

    testofset.insert("1");
    testofset.insert("2");
    testofset.erase("1");
    testofset.insert("3");
    testofset.insert("4");
    testofset.insert("5");
    for (auto it = testofset.begin(); it != testofset.end(); it++) {
        string strtestofset = *it;
        int i = (int)testofset.size();
//		testofset.erase(it);
        i = (int)testofset.size();
    }

    //127. Word Ladder
    string w127_1 = "hit";
    string w127_2 = "cog";
    vector<string> words127 = { "hot", "dot", "dog", "lot", "log", "cog" };
    tempS.ladderLength(w127_1, w127_2, words127);
    w127_1 += 'a';

    //240. Search a 2D Matrix II
    vector<vector<int>> v_240 = { { 1,   4,  7, 11, 15 }, { 2,   5,  8, 12, 19 }, { 3,   6,  9, 16, 22 }, { 10, 13, 14, 17, 24 }, { 18, 21, 23, 26, 30 } };
    vector<vector<int>> v_240_1 = { {5}, {6} };
    vector<vector<int>> v_240_2 = { { 1,   2,  3, 4, 5 },{ 6,   7,  8, 9, 10 },{ 11,   12,  13, 14, 15 },{ 16, 17, 18, 19, 20 },{ 21, 22, 23, 24, 25 } };
    tempS.searchMatrix(v_240_2, 19);

    // test of lower_bound
    vector<int> testlowerbound = { 5, 3, 6, 9 };
    auto testlowerbound1 = std::lower_bound(testlowerbound.begin(), testlowerbound.end(), 4);
    testlowerbound1 = std::lower_bound(testlowerbound.begin(), testlowerbound.end(), 2);
    testlowerbound1 = std::lower_bound(testlowerbound.begin(), testlowerbound.end(), 8);

    //459. Repeated Substring Pattern
    tempS.repeatedSubstringPattern("abcdabcabc");

    int testofwhile = 1;
    while (testofwhile--) {
        int k = 0;
        k++;
    }
    //355. Design Twitter
    unordered_map<int, unordered_set<int>> tweet;

    //76. Minimum Window Substring
//	tempS.minWindow("aaabdabcefaecbef", "abc");
    tempS.minWindow("bdab", "ab");

    // test of sequence
//	int x = 6, y = 7, z = 8, r;
//	r = tempS.testofsequence((x--, y++, x + y), z--);

//159. Longest Substring with At Most Two Distinct Characters
    tempS.lengthOfLongestSubstringTwoDistinct("ccaabbb");

    //395. Longest Substring with At Least K Repeating Characters
    tempS.longestSubstring("aaabb", 3);

    // test istringstream 02/24
    istringstream in0224("0"), in0224_1("");
    int test0224 = -1;
    if (in0224 >> test0224)
        cout << test0224;
    if (in0224 >> test0224)
        cout << test0224;
    if (in0224_1 >> test0224)
        cout << test0224;
    bool i02241 = false, i02242 = false;
    i02241 |= i02242;

    //22. Generate Parentheses
    tempS.generateParenthesis(3);

    //51. N-Queens
    string str51(100, '.');
    vector<string> v51(100, string(100, '.'));

    //test of << >> 03/02/2007
    int a0302 = 0x80000000;
    int a03021 = -1;
    int a03022 = INT_MIN;
    int t0302 = -2;
    int t03021 = INT_MAX;

    t0302 = (t0302 ^ INT_MIN) ^ INT_MAX;
    a03022 = (a03022 ^ INT_MIN) ^ INT_MAX;



    a0302 >>= sizeof(int) * 8 - 1;
    a03021 >>= sizeof(int) * 8 - 1;
    a03022 >>= sizeof(int) * 8 - 1;


    //test time
    time_t testime1 = time(NULL);
    time_t testime2 = time(NULL);
    time_t testime3 = time(NULL);
    time_t testime4 = time(NULL);

    //373. Find K Pairs with Smallest Sums
    vector<int> v373_1 = { 1, 7, 11 };
    vector<int> v373_2 = { 2, 4, 6 };
    tempS.kSmallestPairs(v373_1, v373_2, 3);

    //392. Is Subsequence
    tempS.isSubsequence("abc", "ahbgdc");


    //80. Remove Duplicates from Sorted Array II
    vector<int> nums80 = { 1,1,1,2,2,3 };
    tempS.removeDuplicatesII(nums80);

    // test of enum
    Solution::DismLogLevel testofenum = Solution::DismLogErrorsWarnings;
    testofenum = (Solution::DismLogLevel)100;

    ////39. Combination Sum
    vector<int> v39 = { 5, 3, 2 };
    tempS.combinationSum(v39, 8);

    //29. Divide Two Integers
    tempS.divide(INT_MIN, INT_MIN);

    // test of factorial, 03/10/2017
    vector<unsigned int> test031017;
    test031017 = tempS.factorial(20);
    test031017.resize(300);
    test031017.resize(100);
    test031017 = tempS.factorial(50);
    test031017 = tempS.factorial(100);
//	test031017 = tempS.factorial(10000);
//	test031017 = tempS.factorial(1000000);

    //43. Multiply Strings
    string str43(10, '0');
    tempS.multiply("9", "9");

    //45. Jump Game II
    vector<int> v45 = { 2,1,1,1,1 };
    tempS.jumpII(v45);

    // Endianness Test
    tempS.EndiannessTest();
    tempS.TestVolatileInt();

    // test of static variable
    printStr();
    printStr();
    printStr();

    // test of memory
//	cout << "\n test of memory: " << *testofmemory << " ," << *(++testofmemory);
// test of my strcpy
    tempS.MyStrCpy();


    //Read public certificat;
    std::ifstream ifs0313;
    ifs0313.open("C:\\LZB\\Job\\Doc\\security\\MS Root Certificate DER.cer", ifstream::in | ifstream::binary);
    cout << "\n";

    while (!ifs0313.eof()) {
        char a;
        ifs0313 >> a;
        if (ifs0313.eof())
            break;

//		cout << setfill('0') << setw(2) << hex << (UINT8) (unsigned int) a;

        int i = (a >> 4) & 0x0F;
        int j = a & 0x0F;
        i = (i << 4) + j;
        if (i < 16)
            cout << 0;

        cout << setiosflags(ios::uppercase) << hex << i;

    }
    //test int_min
    int n0314 = INT_MIN;
    int n0314_1 = 0;
    n0314_1 = abs(n0314);
    long l0314 = 0;
    l0314 = labs(n0314);
    long long ll0314 = 0;
    ll0314 = llabs(n0314);
    unsigned int ui0314 = 0;
    ui0314 = abs(n0314);

    //69. Sqrt(x)
    int x69 = 2147395599;

    tempS.mySqrt(x69);

    //74. Search a 2D Matrix
    vector<vector<int>> matrix74 = { {1,1} };
    tempS.searchMatrixI(matrix74, 2);

    //81. Search in Rotated Sorted Array II
    vector<int> v81 = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };

    //60. Permutation Sequence
    tempS.getPermutation60(3, 4);

    //test INT_MAX;
//	int n0315 = INT_MAX + 1;

    //test of enum
    CardType card0316 = CardType::diamond;
//	card0316++;

    //test of system design cards
    Casino casino;
    casino.NormalOperating();

    /*
    for (CardType i = CardType::club; i <= CardType::spade; i++)
        card0316 = i;
        */
    //template test
    TemplateTest<int> templateTest0316(1, 2);
    int tmpInt0316 = templateTest0316.GetMax();

    TemplateTest<char> templateTest0316_1('A', 'B');
    char tmpChar0316 = templateTest0316_1.GetMax();

    //99. Recover Binary Search Tree
    Solution::TreeNode root99_1(3);
    Solution::TreeNode root99_2(1);
    Solution::TreeNode root99_3(2);
    root99_1.left = &root99_2;
    root99_1.right = &root99_3;

    tempS.recoverTree(&root99_1);

    // test of vector and list initialization
    list<int> list0318_1(10, 5);
    list<int> list0318_2(list0318_1);

    vector<int> v0318_1(10, 2);
    vector<int> v0318_2(v0318_1);
//	vector<int> v0318_3(list0318_1);

//130. Surrounded Regions
//	tempS.Test130();
//multiple inheritance test
    MulInheritanceDerived_D1 inheritancetest;
    MulInheritanceDerived_C1 *inheritancetest_p = &inheritancetest;
    int inheritancetest_i = inheritancetest_p->A();

    //37. Sudoku Solver
    tempS.test37();

    //131. Palindrome Partitioning
    tempS.test131();

    //264. Ugly Number II
    tempS.nthUglyNumber(11);

    //313. Super Ugly Number
    tempS.test313();

    //20

}




