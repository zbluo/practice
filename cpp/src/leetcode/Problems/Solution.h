#pragma once
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
//#include<hash_map>
#include<set>
#include<queue>
#include<stack>
#include<unordered_map>
#include<bitset>
#include<unordered_set>
#include<sstream>
#include"TrieNode.h"
#include<random>
#include<ctime>
#include<mutex>
#include<iostream>
#include<algorithm>
using namespace std;


class Solution{
public:
	Solution();
	~Solution();

	struct ListNode {
		int val;
		ListNode* next;
		ListNode(int x) : val(x), next(nullptr) {};
	};

	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode() : val(100), left(nullptr), right(nullptr) {};
		TreeNode(int x, int y) : val(x + y), right(nullptr) {};
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
	} GlobalTreeNode;

	TreeNode operator + (TreeNode &i) { return 0; };
	//test
	Solution* SolutionPointer2PointerTest[5] = { nullptr };

	//116. Populating Next Right Pointers in Each Node
	struct TreeLinkNode {
		int val;
		TreeLinkNode *left, *right, *next;
		TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
	};

/*
	//383
	bool M_CanConstruct(string ransomNote, string magazine);
	bool CanConstruct(string ransomNote, string magazine);

	//387
	int M_FirstUniqChar(string s);
	int FirstUniqChar(string s);

	//389
	char findTheDifference(string s, string t);

	//374
	int guessNumber(int n);
	int guess(int num);

	//396
	int maxRotateFunction(vector<int>& A);

	//397
	int integerReplacement(int n);

	//400
	int findNthDigit(int n);
	int findN(int &m, int &k);

	//401
	vector<string> readBinaryWatch(int num);
	void DFS(int len, int k, int curIndex, int val, vector<int>& vec);

	//404
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};
	int sumOfLeftLeaves(TreeNode* root);

	//405
	string toHex(int num);

	//409
	int longestPalindrome(string s);

	//326
	bool isPowerOfThree(int n);

	//342
	bool isPowerOfFour(int num);

	//345
	string reverseVowels(string s);

	//349
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2);

	//283
	void moveZeroes(vector<int>& nums);

	//290
	bool wordPattern(string pattern, string str);

	//299
	string getHint(string secret, string guess);

	//303
	vector<int> intNums = { 0 };
	void NumArray(vector<int> &nums);
	int sumRange(int i, int j);

	//219
	bool containsNearbyDuplicate(vector<int>& nums, int k);

	//223
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H);

	//225
	queue<int> q1, q2;
	void push(int x);
	void pop();
	int top();
	bool empty();

	//234


	ListNode* reverse(ListNode* head);
	ListNode* partition(ListNode* head);
	bool isPalindrome(ListNode* head);

	//235
	struct TreeNode {
		int val;
		TreeNode * left;
		TreeNode * right;
	};

	TreeNode * ptrTreeNode;

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);

	//236
	void l236();
	TreeNode* lowestCommonAncestor_236(TreeNode* root, TreeNode* p, TreeNode* q);
	bool getPath(TreeNode* root, TreeNode* t, vector<TreeNode*>& path);

	//237
	void deleteNode(ListNode* node);

	//6
	string convert(string s, int nRows);

	//7
	int reverse(int x);

	//9
	bool isPalindrome(int x);

	//13
	int romanToInt(string s);

	//14
	string longestCommonPrefix(vector<string>& strs);
	
	//19
	ListNode* removeNthFromEnd(ListNode* head, int n);

	//20
	bool isValid(string s);

	//21
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);


	//26
	int removeDuplicates(vector<int>& nums);

	//27
	int removeElement(vector<int>& nums, int val);

	//28
	int strStr(string haystack, string needle);

	//205
	bool isIsomorphic(string s, string t);

	//203
	ListNode* removeElements(ListNode* head, int val);

	//172
	int trailingZeroes(int n);

	//
	int countPrimes(int n);

	//202
	bool isHappy(int n);

	//198
	int rob(vector<int>& nums);
*/

    //190
    uint32_t reverseBits(uint32_t n);

	//171
	int titleToNumber(string s);

	//169
	int majorityElement(vector<int>& nums);

	//168
	string convertToTitle(int n);

	//160
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB);

	//141
	bool hasCycle(ListNode *head);

	//119
	vector<int> getRow(int rowIndex);

	//118
	vector<vector<int>> generate(int numRows);

	//58
	int lengthOfLastWord(string s);

	//66
	vector<int> plusOne(vector<int>& digits);

	//67
	string addBinary(string a, string b);

	//88. Merge Sorted Array
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);

	//100. Same Tree
	bool isSameTree(TreeNode* p, TreeNode* q);

	//101. Symmetric Tree
	bool isSymmetric(TreeNode* root);
	bool isSymmetric(TreeNode* left, TreeNode* right);

	//102. Binary Tree Level Order Traversal
	vector<vector<int>> levelOrder(TreeNode* root);
	void levelOrder(TreeNode* root, int depth, vector<vector<int>>& v);

	//111. Minimum Depth of Binary Tree
	int minDepth(TreeNode* root);
	int minDepth(TreeNode* root, int depth);

	//110. Balanced Binary Tree
	int height(TreeNode* root);
	bool isBalanced(TreeNode *root);

	//136. Single Number
	int singleNumber(vector<int>& nums);

	//121. Best Time to Buy and Sell Stock
	int maxProfit(vector<int>& prices);

	//123. Best Time to Buy and Sell Stock III
	int maxProfit123(vector<int>& prices);

	//38. Count and Say
	string countAndSay(int n);

	//376. Wiggle Subsequence
	int wiggleMaxLength376(vector<int>& nums);

	//113. Path Sum II
	vector<vector<int>> pathSum(TreeNode* root, int sum);
	void pathSum(TreeNode* root, int sum, vector<vector<int>>& res, vector<int> path);
	void testVector(vector<int>& v);
	void testVector(vector<int> v, int i);

	//108. Convert Sorted Array to Binary Search Tree
	TreeNode* sortedArrayToBST(vector<int>& nums);
	TreeNode* sortedArrayToBST(int left, int right, vector<int>& nums);

	//145. Binary Tree Postorder Traversal
	vector<int> postorderTraversal(TreeNode* root);

	//94. Binary Tree Inorder Traversal
	vector<int> inorderTraversal(TreeNode* root);

	//144. Binary Tree Preorder Traversal
	vector<int> preorderTraversal(TreeNode* root);

	//105. Construct Binary Tree from Preorder and Inorder Traversal
	TreeNode* buildTree105(vector<int>& preorder, vector<int>& inorder);
	TreeNode* buildTree105(vector<int>& preorder, int begin1, int end1, vector<int>& inorder, int begin2, int end2);

	//106. Construct Binary Tree from Inorder and Postorder Traversal
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder);
	TreeNode* buildTree(vector<int>& inorder, int begin1, int end1, vector<int>& postorder, int begin2, int end2);

	//416. Partition Equal Subset Sum
	bool canPartition(vector<int>& nums);

	//415. Add Strings
	string addStrings(string num1, string num2);

	//410. Split Array Largest Sum
	int splitArray(vector<int>& nums, int m);
	bool splitable(vector<int>& nums, int m, int largestSum);

	//vm ware pracice, flip 0 and 1
	pair<int, int> VMWareFlip(string s);

	// 315
	struct BST {
		int val;
		int smaller;
		BST* left;
		BST* right;
		BST(int x, int y) : val(x), smaller(y), left(nullptr), right(nullptr) {};
	};
	vector<int> countSmaller(vector<int>& nums);
	int insertBST(BST* &root, int value);

	//170. Two Sum III - Data structure design
	void add(int number);
	bool find(int value);

	//167. Two Sum II - Input array is sorted  
	vector<int> twoSum(vector<int>& numbers, int target);

	//2. Add Two Numbers 
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

	//151. Reverse Words in a String
	void reverseWords(string &s);

	//414. Third Maximum Number
	int thirdMax(vector<int>& nums);

	//3. Longest Substring Without Repeating Characters
	int lengthOfLongestSubstring(string s);

	//5. Longest Palindromic Substring
	string longestPalindrome(string s);

	//15. 3Sum 
	vector<vector<int>> threeSum(vector<int>& nums);

	//18. 4Sum
	vector<vector<int>> fourSum(vector<int>& nums, int target);

	//433. Minimum Genetic Mutation
	int minMutation(string start, string end, vector<string>& bank);

	//432. All O`one Data Structure
	void inc(string key);
	void dec(string key);
	string getMaxKey();
	string getMinKey();


	//432. All O`one Data Structure
	struct bucket {
		int val;
		unordered_set<string> keys;
		bucket(int x = 0, unordered_set<string> y = {}) : val(x), keys(y) {}
	};

	//348. Design Tic-Tac-Toe
	int move(int row, int col, int player);
	void TicTacToe(int n);

	//186. Reverse Words in a String II
	void reverseWords2(string &s);

	//148. Sort List
	ListNode* sortList(ListNode* head);
	ListNode* sortList_rec(ListNode* head);

	//75. Sort Colors
	void sortColors(vector<int>& nums);
	void sortColors(vector<int>& nums, int left, int right);

	//200. Number of Islands
	int numIslands(vector<vector<char>>& grid);
	void dfsReset(vector<vector<char>>& grid, int i, int j);

	//218. The Skyline Problem
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings);

	//297. Serialize and Deserialize Binary Tree
	void serialize(TreeNode* root, ostringstream& out);
	TreeNode* deserialize(istringstream& in);
	string serialize(TreeNode* root);
	TreeNode* deserialize(string data);
	//268. Missing Number 
	int missingNumber(vector<int>& nums);

	//116. Populating Next Right Pointers in Each Node 
	void connect(TreeLinkNode *root);
	//73. Set Matrix Zeroes
	void setZeroes(vector<vector<int>>& matrix);

	//98. Validate Binary Search Tree 
	bool isValidBST(TreeNode* root);

	////208. Implement Trie (Prefix Tree) Pointer to Pointer Test
	void PointertoPointerTest();

	// 23. Merge k Sorted Lists
	void mergeKLists();
	ListNode* mergeKLists(vector<ListNode*>& lists);
	ListNode* partitionSort(ListNode* root);
	ListNode* mergeNodes(ListNode* left, ListNode* right);

	//272. Closest Binary Search Tree Value II
	vector<int> closestKValues(TreeNode* root, double target, int k);

	//212. Word Search II 
	TrieNode* buildTrie(vector<string>& words);
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words);
	void dfs(vector<vector<char>>& board, int i, int j, TrieNode* p, vector<string>& ans);

	//333. Largest BST Subtree 
	struct treeInfo {
		bool isBST;
		int nodes;
		int max;
		int min;
		treeInfo(bool a = true, int b = 0, int c = 0, int d = 0) : isBST(a), nodes(b) {}
	};
	int largestBSTSubtree(TreeNode* root);
	treeInfo* bstSubTree(TreeNode* root);

	void morrisIn(TreeNode* head);
	void morrisPre(TreeNode* head);

	//451. Sort Characters By Frequency
	string frequencySort(string s);
	static const bool cmp451(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}

	//316. Remove Duplicate Letters
	string removeDuplicateLetters(string s);

	//71. Simplify Path
	string simplifyPath(string path);

	//165. Compare Version Numbers
	int compareVersion(string version1, string version2);
	void extraction(string s, vector<int>& v);

	//91. Decode Ways
	int numDecodings(string s);

	//125. Valid Palindrome
	bool isPalindrome(string s);
	bool invalid(char c);

	//25. Reverse Nodes in k-Group
	ListNode* reverseKGroup(ListNode* head, int k);
	ListNode* reverseLN(ListNode* head, int k);
	void test25();

	//56. Merge Intervals
	struct Interval {
		int start;
		int end;
		Interval() : start(0), end(0) {}
		Interval(int s, int e) : start(s), end(e) {}
		
	};
	vector<Interval> merge(vector<Interval>& intervals);
	void test56();

//interview 2016/11/18

//249. Group Shifted Strings
	vector<vector<string>> groupStrings(vector<string>& strings);
	string shift(string& s);

	//78. Subsets
	vector<vector<int>> subsets(vector<int>& nums);

	//337. House Robber III
	int robIII(TreeNode* root);
	vector<int> robSub(TreeNode* root);

	//Integer to English Words
	const string digits[20] = { "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
	const string tens[10] = { "Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
	string int2string(int n);
	string numberToWords(int num);

	//heap sort
	void HeapAdjust(int array[], int i, int nLength);
	void HeapSort(int array[], int length);

	//54 Spiral Matrix
	vector<int> spiralOrder(vector<vector<int>>& matrix);

	//236
	struct Frame {
		TreeNode* node;
		Frame* parent;
		vector<TreeNode*> subs;
	};
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);

	//48. Rotate Image
	void rotate(vector<vector<int>>& matrix);

	//1 Two Sum
	vector<int> twoSum_I(vector<int>& nums, int target);

	//103. Binary Tree Zigzag Level Order Traversal
	vector<vector<int>> zigzagLevelOrder(TreeNode* root);
	void zigzagLevelOrder(TreeNode* root, int depth, vector<vector<int>>& v);

	// 53. Maximum Subarray
	int maxSubArray(vector<int>& nums);

	//117. Populating Next Right Pointers in Each Node II Add to List
	void connect_I(TreeLinkNode *root);
	TreeLinkNode* nextChild(TreeLinkNode* cur);

	//174. Dungeon Game
	int calculateMinimumHP(vector<vector<int>>& dungeon);

	//33. Search in Rotated Sorted Array
	int search(vector<int>& nums, int target);

	//153. Find Minimum in Rotated Sorted Array
	int findMin(vector<int>& nums);

	//24. Swap Nodes in Pairs
	ListNode* swapPairs(ListNode* head);

	//215. Kth Largest Element in an Array Add to List
	int partition215(vector<int>& nums, int left, int right);
	int findKthLargest(vector<int>& nums, int k);

	//191. Number of 1 Bits
	int hammingWeight(uint32_t n);

	//23. Merge k Sorted Lists
	ListNode* mergeKLists23(vector<ListNode*>& lists);
	struct myComp23 {
		bool operator() (const ListNode* l1, const ListNode* l2) {
			return l1->val > l2->val;
		}
	};

	//46. Permutations Add to List
	vector<vector<int> > permute(vector<int> &num);
	void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result);

	//47. Permutations II Add to List
	vector<vector<int>> permuteUnique(vector<int>& nums);
	void permuteUnique(vector<int> &num, int begin, vector<vector<int> > &result);

	//112. Path Sum
	bool hasPathSum(TreeNode* root, int sum);

	//124. Binary Tree Maximum Path Sum 
	int maxPathSum(TreeNode* root);
	int maxPathSum(TreeNode* root, int &maxSum);

	//114. Flatten Binary Tree to Linked List
	void flatten(TreeNode* root);

	//55. Jump Game 
	bool canJump(vector<int>& nums);


	//92. Reverse Linked List II
	void test92();
	ListNode* reverseBetween(ListNode* head, int m, int n);

	// Check wether a binary tree is a full binary tree
	bool isFullBinaryTree(TreeNode* root);

	//change a binary tree to double linked list
	TreeNode* changeBinaryTreeToDoubleLinkedList(TreeNode* root);


	//448. Find All Numbers Disappeared in an Array
	vector<int> findDisappearedNumbers(vector<int>& nums);

	//338. Counting Bits
	vector<int> countBits(int num);

	//401. Binary Watch Add to List
	vector<string> readBinaryWatch(int num);

	//460. LFU Cache Add to List
	void LFUCache(int capacity);
	int get_460(int key);
	void set_460(int key, int value);
	void increaseFreq(int key);
	list<pair<int, list<int>>>::iterator incfreq(list<pair<int, list<int>>>::iterator);

	//457. Circular Array Loop
	bool circularArrayLoop(vector<int>& nums);
	int getIndex(int i, vector<int>& nums);

	//328. Odd Even Linked List 
	ListNode* oddEvenList(ListNode* head);

	//139. Word Break Add to List
	bool wordBreak(string s, unordered_set<string>& wordDict);
	TreeNode* closestValue(TreeNode* root, TreeNode* p, TreeNode*& closest);

	//152. Maximum Product Subarray Add to List
	int maxProduct(vector<int>& nums);

	//96. Unique Binary Search Trees
	int numTrees(int n);

	//419. Battleships in a Board
	int countBattleships(vector<vector<char>>& board);

	//140. Word Break II 
	unordered_map<string, vector<string>> hashmap_140;
	vector<string> wordBreak_140(string s, vector<string>& wordDict);
	vector<string> combine(string s, vector<string> pre);

	//11. Container With Most Water Add to List 
	int maxArea(vector<int>& height);

	//188. Best Time to Buy and Sell Stock IV 
	int maxProfit_IV(int k, vector<int>& prices);
	int maxProfit_IV(vector<int>& prices);

	//72. Edit Distance Add to List
	int minDistance(string word1, string word2);

	//70. Climbing Stairs Add to List
	int climbStairs(int n);

	//450. Delete Node in a BST Add to List
	TreeNode* deleteNode(TreeNode* root, int key);
	TreeNode* findMinOfTree(TreeNode* node);

	//412. Fizz Buzz Add to List
	vector<string> fizzBuzz(int n);

	//12. Integer to Roman Add to List
	string intToRoman(int num);

	//42. Trapping Rain Water Add to List
	int trap(vector<int>& height);

	//137. Single Number II Add to List
	int singleNumber_II(vector<int>& nums);

	//319. Bulb Switcher Add to List
	int bulbSwitch(int n);

	//461. Hamming Distance
	int hammingDistance(int x, int y);

	//150. Evaluate Reverse Polish Notation Add to List
	int evalRPN(vector<string>& tokens);
	int cal(int a, int b, string token);

	//115. Distinct Subsequences Add to List
	int numDistinct(string s, string t);

	//64. Minimum Path Sum Add to List
	int minPathSum(vector<vector<int>>& grid);

	//229. Majority Element II Add to List
	vector<int> majorityElement_II(vector<int>& nums);

	//343. Integer Break Add to List
	int integerBreak(int n);

	//62. Unique Paths 
	int uniquePaths(int m, int n);

	//Quick sort
	void QuickSort(vector<int>& nums);
	void QuickSort(vector<int>& nums, int left, int right);

	//Merge Sort
	void MergeSort(vector<int>& nums);
	void MergeSort(vector<int>& nums, int left, int right);
	void MergeArray(vector<int>& nums, int left, int right, int mid);


	//243. Shortest Word Distance 
	int shortestDistance(vector<string>& words, string word1, string word2);


	//244. Shortest Word Distance II 
	void WordDistance(vector<string> words);
	int shortest(string word1, string word2);
	unordered_map<string, vector<int>> hashmap_244;

	//Test of Sudoku
	bool Sudoku(vector<vector<int>> nums);

	// 146. LRU Cache 
	void LRUCache(int capacity);
	int get_146(int key);
	void put_146(int key, int value);
	int mycapacity_146;
	unordered_map<int, list<pair<int, int>>::iterator> hashmap_146;
	list<pair<int, int>> mylist_146;

	//test of struct
	struct testofstruct {
		string str;
		testofstruct* children[26];
		testofstruct() : str(nullptr) {
		}
	};

	// 300. Longest Increasing Subsequence
	int lengthOfLIS(vector<int>& nums);

	// 	452. Minimum Number of Arrows to Burst Balloons 
	static const bool cmpArrow(pair<int, int> a, pair<int, int> b);
	int findMinArrowShots(vector<pair<int, int>>& points);

	//8. String to Integer (atoi) 
	int myAtoi(string str);


	//238. Product of Array Except Self 
	vector<int> productExceptSelf(vector<int>& nums);

	//162. Find Peak Element 
	int findPeakElement(vector<int>& nums);

	//285. Inorder Successor in BST 
	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p);

	// 4. Median of Two Sorted Arrays
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

	// MS OTS 02/07/2017
	std::set<pair<int, int>> ClosestKPoints(std::set<pair<int, int>> allpoints, pair<int, int> ref, int k);
	int distance(pair<int, int>p1, pair<int, int>p2);

	//147. Insertion Sort List 
	ListNode* insertionSortList(ListNode* head);

	//35. Search Insert Position 
	int searchInsert(vector<int>& nums, int target);

	// 380. Insert Delete GetRandom O(1) 
	void RandomizedSet();
	bool insert(int val);
	bool remove(int val);
	int getRandom();
	unordered_map<int, int> hashmap_380;
	vector<int> v_380;


	//516. Longest Palindromic Subsequence 
	int longestPalindromeSubseq(string s);

	//127. Word Ladder 
	int ladderLength(string beginWord, string endWord, vector<string>& wordList);

	//240. Search a 2D Matrix II 
	bool searchMatrix(vector<vector<int>>& matrix, int target);
	bool binarySearch(vector<vector<int>>& matrix, int &starti, int &startj, int endi, int endj, bool row, int target);

	//239. Sliding Window Maximum 
	vector<int> maxSlidingWindow(vector<int>& nums, int k);

	//17. Letter Combinations of a Phone Number 
	vector<string> letterCombinations(string digits);

	//49. Group Anagrams 
	vector<vector<string>> groupAnagrams_49(vector<string>& strs);
	string convert_49(string& str);

	//199. Binary Tree Right Side View 
	vector<int> rightSideView(TreeNode* root);
	void rightSideView(TreeNode*& root, vector<int>& ans, int depth);

	//KMP table
	vector<int> PrefixFunction(string S);

	//508. Most Frequent Subtree Sum 
	vector<int> findFrequentTreeSum(TreeNode* root);
	int findFrequentTreeSum(TreeNode* root, unordered_map<int, int>& hashmap);

	//459. Repeated Substring Pattern 
	bool repeatedSubstringPattern(string str);

	//61. Rotate List 
	ListNode* rotateRight(ListNode* head, int k);

	//344. Reverse String 
	string reverseString(string s);


	//355. Design Twitter 
	/** Initialize your data structure here. */
	void Twitter();
	void postTweet(int userId, int tweetId);
	vector<int> getNewsFeed(int userId);
	void follow(int followerId, int followeeId);
	void unfollow(int followerId, int followeeId);
	unordered_map<int, deque<pair<int, time_t>>> tweet; // key -> user id, value -> set of tweet id / time
	unordered_map<int, unordered_set<int>> follower;

	//132. Palindrome Partitioning 
	int minCut(string s);

	//76. Minimum Window Substring
	string minWindow(string s, string t);
	bool IsAnagram(vector<int>& sv, vector<int>& tv);
	void shrinkWindow(string &s, vector<int> &sv, vector<int> &tv, int &start, int&end);


	//test of sequence
	int testofsequence(int a, int b);

	//159. Longest Substring with At Most Two Distinct Characters
	int lengthOfLongestSubstringTwoDistinct(string s);

	//340. Longest Substring with At Most K Distinct Characters 
	int lengthOfLongestSubstringKDistinct(string s, int k);

	//395. Longest Substring with At Least K Repeating Characters
	int longestSubstring(string s, int k);
	int longestSubstring(string &s, int left, int right, int k);

	//276. Paint Fence
	int numWays(int n, int k);

	//30. Substring with Concatenation of All Words 
	vector<int> findSubstring(string s, vector<string>& words);

	//10. Regular Expression Matching
	bool isMatch(string s, string p);
	bool isMatch(char a, char b);

	//22. Generate Parentheses 
	vector<string> generateParenthesis(int n);
	void generateParenthesis(int left, int right, vector<string>& ans, string s);

	//148. Sort List 02/25/2017, 27 minutes
	ListNode* sortList148(ListNode* head);
	ListNode* split148(ListNode *head, int step);
	ListNode* merge148(ListNode *left, ListNode *right, ListNode *tail);

	//503. Next Greater Element II
	vector<int> nextGreaterElements(vector<int>& nums);

	//496. Next Greater Element I 
	vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums);

	//214. Shortest Palindrome
	string shortestPalindrome(string s);

	//131. Palindrome Partitioning
	void test131();
	vector<vector<string>> partition131(string s);
	void dfs131(int start, string s, vector<string> &path, vector<vector<string>> &ans);
	bool isPalin131(string s, int start, int end);
	void dfs131(int start, string s, vector<string> &path, vector<vector<string>> &ans, vector<vector<bool>> &palindrome);

	//77. Combinations
	vector<vector<int>> combine77(int n, int k);
	void dfs77(int k, int beg, int n, vector<int> &path, vector<vector<int>> &ans);

	//90. Subsets II
	vector<vector<int>> subsetsWithDup(vector<int>& nums);
	void dfs90(int begin, vector<int> &nums, vector<int> path, vector<vector<int>> &ans);

	//51. N-Queens
	vector<vector<string>> solveNQueens(int n);
	bool Queens(vector<string> &board, int col, vector<vector<string>> &ans);
	bool isSafe51(vector<string> &board, int row, int col);

	// 52. N-Queens II
	int totalNQueens52(int n);
	bool Queens52(vector<vector<bool>> &board, int col, int &ans);
	bool isSafe52(vector<vector<bool>> &board, int row, int col);

	//373. Find K Pairs with Smallest Sums
	vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k);

	//392. Is Subsequence
	bool isSubsequence(string s, string t);

	//253. Meeting Rooms II
	int minMeetingRooms(vector<Interval>& intervals);

	//252. Meeting Rooms
	bool canAttendMeetings(vector<Interval>& intervals);

	//80. Remove Duplicates from Sorted Array II
	int removeDuplicatesII(vector<int>& nums);

	//82. Remove Duplicates from Sorted List II
	ListNode* deleteDuplicatesII(ListNode* head);

	//402. Remove K Digits 
	string removeKdigits(string num, int k);

	//143. Reorder List
	void reorderList(ListNode* head);
	ListNode* reverseList(ListNode *head);

	//39. Combination Sum
	vector<vector<int>> combinationSum(vector<int>& candidates, int target);
	void dfs39(vector<int>& candidates, int target, int index, vector<int> path, vector<vector<int>> &res);

	//40. Combination Sum II
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target);
	void dfs40(vector<int>& candidates, int target, vector<int> path, vector<vector<int>>& res, int index);

	//216. Combination Sum III
	vector<vector<int>> combinationSum3(int k, int n);
	void dfs216(int k, int n, vector<int> path, vector<vector<int>>& res, int index);

	//16. 3Sum Closest
	int threeSumClosest(vector<int>& nums, int target);

	//29. Divide Two Integers
	int divide(int dividend, int divisor);

	//31. Next Permutation
	void nextPermutation(vector<int>& nums);

	//32. Longest Valid Parentheses
	int longestValidParentheses(string s);

	//41. First Missing Positive 
	int firstMissingPositive(vector<int>& nums);

	// test of factorial, 03/10/2017
	vector<unsigned int> factorial(unsigned int n);
	int factorial(unsigned int n, unsigned int res);

	//43. Multiply Strings 
	string multiply(string num1, string num2);

	//45. Jump Game II
	int jumpII(vector<int>& nums);

	// Endianness Test
	bool EndiannessTest();

	// test of volatile
	void TestVolatileInt();

	// test of static
	static int testofstatic;
	int testofstatic1 = 0;

	// test of my strcpy
	void MyStrCpy();

	//test of tailrecursive: fibonacci sequence
	// calling for the function:: int res = fibonacci(1, 0, 10);
	int fibonacci(int a, int b, int n);

	//50. Pow(x, n) 
	double myPow(double x, int n);
	double myPow(double x, unsigned int n);

	//69. Sqrt(x) 
	int mySqrt(int x);

	//74. Search a 2D Matrix
	bool searchMatrixI(vector<vector<int>>& matrix, int target);

	// 81. Search in Rotated Sorted Array II
	bool search81(vector<int>& nums, int target);

	//60. Permutation Sequence 
	string getPermutation60(int n, int k);
	void getPermutation60(string seq, int k, vector<string>& res, int index);

	//128. Longest Consecutive Sequence 
	int longestConsecutive(vector<int>& nums);

	//95. Unique Binary Search Trees II 
	vector<TreeNode*> generateTrees(int n);
	vector<TreeNode*> generateTrees(int start, int end);

	//63. Unique Paths II
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);

	//133. Clone Graph
	struct UndirectedGraphNode {
		int label;
		vector<UndirectedGraphNode *> neighbors;
		UndirectedGraphNode(int x) : label(x) {};
	};

	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node);
	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hashmap133;

	//93. Restore IP Addresses
	vector<string> restoreIpAddresses(string s);
	bool isValid93(string s);

	//134. Gas Station
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost);

	//99. Recover Binary Search Tree 
	void recoverTree(TreeNode* root);
	void FindTarget(TreeNode *pre, TreeNode *cur, TreeNode *&target1, TreeNode *&target2);

	//86. Partition List
	ListNode* partition(ListNode* head, int x);

	//129. Sum Root to Leaf Numbers
	int sumNumbers(TreeNode* root);
	void sumNumbers(TreeNode* root, int path, int &result);

	//120. Triangle
	int minimumTotal(vector<vector<int>>& triangle);

	//130. Surrounded Regions
	void Test130();
	void solve(vector<vector<char>>& board);
	void SetDFS(vector<vector<char>> &board, int i, int j, char src, char dest);
	void SetBoarder(vector<vector<char>> &board, char src, char dest);

	//37. Sudoku Solver
	void test37();

	void solveSudoku(vector<vector<char>>& board);
	bool solveSudoku(vector<vector<char>>& board, vector<pair<int, int>> &pos, int cur);
	bool isValid37(vector<vector<char>> &board, int row, int col, char c);

	//264. Ugly Number II
	int nthUglyNumber(int n);
	//263. Ugly Number
	bool isUgly(int num);
	//313. Super Ugly Number
	int nthSuperUglyNumber(int n, vector<int>& primes);
	void test313();

	//test github
	int TestGitHub();

	//end
	void end();
	enum DismLogLevel
	{
		DismLogErrors = 0,
		DismLogErrorsWarnings,
		DismLogErrorsWarningsInfo
	};

	//geeks

	//Finding Profession geeks
	char find_geeks1(int level, int pos);
	//geeks : Dynamic Programming | Set 7 (Coin Change)
	int count(int S[], int m, int n);

	//test priority_ques
	void test_priority_queue();

	//test map
	void test_map();

private:
	// test of volatile
	int nonVolatileInt = 0;
	volatile int volatileInt = 0;

	unordered_multiset<int> nums_170;

	//433. Minimum Genetic Mutation
	bool isMutation(string m, string n);
	struct mutation {
		string gen;
		int depths;
		mutation(string x = "", int y = 0) : gen(x), depths(y) {}
	};

	//432. All O`one Data Structure
	list<bucket> buckets;
	unordered_map<string, list<bucket>::iterator> mapOfKey;

	////348. Design Tic-Tac-Toe
	volatile int size348;
	vector<int> rows348;
	vector<int> cols348;
	int diagonal348, anti_diagonal348;

	//460. LFU Cache 
	struct dequeKeys {
		int freq;
		list<int> keys;
		dequeKeys *pre;
		dequeKeys *next;
		dequeKeys(int a) : freq(a), pre(nullptr), next(nullptr) {}
	};

	struct pri {
		int freq;
		list<int> keys;
		pri(int a = 0): freq(a) {}
	};

	unordered_map<int, pair<int, list<pair<int, list<int>>>::iterator>> hashmap_460;
	list<pair<int, list<int>>> mylist_460;
	int mycapacity;

	int capacity;
	dequeKeys *head = nullptr, *tail = nullptr;
	unordered_map<int, pair<int, dequeKeys*>> hashmap;


};

class mycomparationclass {
private:
	pair<int, int> refp;
public:
	mycomparationclass(pair<int, int>& a) { refp = a; }

	bool operator() (pair<int, int> p1, pair<int, int> p2) {
		return distance(p1, refp) > distance(p2, refp);
	}

	int distance(pair<int, int> p1, pair<int, int> p2) {
		return (int)sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
	}
};

enum class CardType {
	club,
	heart,
	diamond,
	spade,
	end_of_list
};

//multiple inheritance test
class MulInheritanceClass {
public:
	virtual int A() = 0;
	int AA() { return 0; }
};
class MulInheritanceInterface {
public:
	virtual int A() = 0;
};
class MulInheritanceDerived_B1 : public MulInheritanceClass {
public:
	int A() { return 1; }
};
class MulInheritanceDerived_C1 : public MulInheritanceClass {
public:
	int A() { return 2; }
};
class MulInheritanceDerived_D1 : public MulInheritanceDerived_B1, public  MulInheritanceDerived_C1 {
public:
	int D() { return 3; }
};

inline bool fncomp(char& a, char& b) {return a > b;};

class clacomp {
public:
    bool operator() (const char& a, const char& b) const {
        return a > b;
    }
};
