#include "Solution.h"

static int testofstatic3 = 0;

Solution::Solution()
{
	testofstatic3 = 1;
}

Solution::~Solution()
{
}



/*
//383
bool Solution::M_CanConstruct(string ransomNote, string magazine)
{
	for (auto tempIT = ransomNote.begin(); tempIT != ransomNote.end(); tempIT++)
	{
		auto find = magazine.find(*tempIT);
		if (find != string::npos) 
			magazine.erase(find);
		else 
			return false;
	}
	return true;
}
bool Solution::CanConstruct(string ransomNote, string magazine)
{
	int count[26] = { 0 };
	for (auto tempIT = ransomNote.begin(); tempIT != ransomNote.end(); tempIT++)
	{ 
		count[*tempIT - 'a']++;
	}
	for (auto tempIT = magazine.begin(); tempIT != magazine.end(); tempIT++)
	{
		count[*tempIT - 'a']--;
	}
	for (int i = 0; i < 26; i++)
		if (count[i] > 0)
			return false;
	return true;
}

//387
int Solution::M_FirstUniqChar(string s)
{
	vector<int> count(26, 0);
	for(int i = 0; i < s.size(); i++)
		count[s[i] - 'a']++;
	for(int i = 0; i < s.size(); i++)
		if(count[s[i] - 'a'] == 1)
			return i;
	return -1;
}
int Solution::FirstUniqChar(string s)
{
	if (s.empty()) return -1;

	map<char, int> m;

	for (int i = 0; i < (int)s.length(); i++)
		m[s[i]]++;
	for (int i = 0; i < (int)s.length(); i++)
		if (m[s[i]] == 1) return i;

	return -1;
}

//389
char Solution::findTheDifference(string s, string t)
{
	int tempS[26] = { 0 };
	int tempT[26] = { 0 };
	char result = NULL;
	int len = s.length();
	int i = 0;

	for (i = 0; i < len; i++)
	{
		(tempS[s[i] - 97])++;
		(tempT[t[i] - 97])++;
	}

	(tempT[t[len] - 97])++;

	for (int i = 0; i < 26; i++)
	{
		if (tempS[i] != tempT[i])
			result = (char)(i + 97);
	}

	return result;
}

//374
int Solution::guess(int num)
{
	int myNum = 87;
	if (myNum < num) 
		return -1;
	else if (myNum > num) 
		return 1;
	else
		return 0;
}

int Solution::guessNumber(int n)
{
	int low = 1, high = n, res = 0;
	int mid = 0;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		res = guess(mid);
		if (res < 0)
			high = mid - 1;
		else if (res > 0)
			low = mid + 1;
		else
			return mid;
	}
	return 0;
}

//396
int Solution::maxRotateFunction(vector<int>& A)
{
	int len = A.size();
	if (len == 0) return 0;
	int sum = 0, max = 0, pre = 0;
	for (int i = 0; i< len; i++)
	{
		sum += A[i];
		pre += i * A[i];
	}
	max = pre;
	for (int i = len - 1; i > 0; i--)
	{
		pre += (sum - len * A[i]);
		if (pre > max)
			max = pre;
	}
	return max;
}

//397
int Solution::integerReplacement(int n)
{
	if (n == 1)
		return 0;
	else if (n == INT_MAX)
		return 2 + integerReplacement((n >> 1) + 1);

	if (n % 2)
		return min(1 + integerReplacement(n + 1), 1 + integerReplacement(n - 1));

	return 1 + integerReplacement(n >> 2);
}

//400
int Solution::findNthDigit(int n)
{
	long digit = 1, first = 1, base = 9;
	string s;
	while (n > base*digit)
	{
		n -= base*(digit++);
		first = pow(10, digit -1);
		base *= 10;
	}
	s = to_string(first + (n - 1) / digit);
	return s[(n - 1) % digit] - '0';
}

int Solution::findN(int &m, int &k)
{
	int tmpL = k * pow(10, k - 1);
	if (k == 1) return m;
	else
	{
		while (m > tmpL)
			m -= tmpL;
		k--;
		findN(m, k);
	}
}

//401
vector<string> Solution::readBinaryWatch(int num)
{
	vector<string> res;

	for (int i = max(0, num - 6); i <= min(4, num); i++)
	{
		vector<int> v1, v2;
		DFS(4, i, 0, 0, v1);
		DFS(6, num - i, 0, 0, v2);
		for (auto val1 = v1.begin(); val1 != v1.end(); val1++)
		{
			for (auto val2 = v2.begin(); val2 != v2.end(); val2++)
			{
				string s = (to_string(*val2).size() == 1 ? "0" : "") + to_string(*val2);
				res.push_back(to_string(*val1) + ":" + s);
			}
		}
	}
	return res;
}

void Solution::DFS(int len, int k, int loc, int val, vector<int> &v)
{
	if (k == 0 && len == 4 && val<12) v.push_back(val);
	if (k == 0 && len == 6 && val<60) v.push_back(val);
	if (k == 0 || loc == len) return;

	DFS(len, k, loc + 1, val, v);
	val += pow(2, loc);
	k--;
	loc++;
	DFS(len, k, loc, val, v);
}

//404
int Solution::sumOfLeftLeaves(TreeNode* root) {
	if(root == nullptr) return 0;
	if (root->left && !root->left->left && !root->left->right)
		return root->left->val + sumOfLeftLeaves(root->right);
	return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}

//405
string Solution::toHex(int num) {

	string tmpH = { '0','1','2','3','4','5','6','7','8','9','a', 'b', 'c', 'd', 'e', 'f' };
	unsigned int num_ = num;
	string res;

	if (num == 0) return "0";
	if (num < 0)
		num_ = ~abs(num) + 1;

	while (num_)
	{
		res = tmpH[num_ % 16] + res;
		num_ = num_ >> 4;
	}
	return res;

}

//409
int Solution::longestPalindrome(string s) {
	int le[58] = { 0 };
	bool odd = false;
	int  res = 0;
	
	for (auto c : s)
		le[c - 'A']++;

	for (int i = 0; i < 58; i++)
	{
		if (le[i] % 2 == 0)
		res += le[i];
		else
		{
			res += (le[i] - 1);
			odd = true;
		}
	}
	if (odd) return res + 1;
	return res;
}

//326
bool Solution::isPowerOfThree(int n) {
	double res = log10(n) / log10(3);
	return (res - int(res)) == 0;
}

//342
bool Solution::isPowerOfFour(int num) {
	if (num <= 0) return false;
	if (num & (num - 1)) return false;
	if (num & 0x55555555) return true;
	return false;
}

//345
string Solution::reverseVowels(string s) {
	string v;

	for (auto it = s.begin(); it != s.end(); it++)
		if (*it == 'A' || *it == 'a' || *it == 'E' || *it == 'e' || *it == 'I' || *it == 'i' || *it == 'O' || *it == 'o' || *it == 'U' || *it == 'u')
		{
			v.push_back(*it);
			*it = 'A';
		}

	for (auto it = s.begin(); it != s.end(); it++)
		if (*it == 'A')
		{
			*it = v.back();
			v.pop_back();
		}
	return s;
}

//349
vector<int> Solution::intersection(vector<int>& nums1, vector<int>& nums2) 
{
	set<int> tmpS;
	vector<int> res;
	for (auto it = nums1.begin(); it != nums1.end(); it++)
		tmpS.insert(*it);
	for (auto it = nums2.begin(); it != nums2.end(); it++)
	{
		if (tmpS.find(*it) != tmpS.end())
		{
			res.push_back(*it);
			tmpS.erase(*it);
		}
	}
	return res;
}

//283
void Solution::moveZeroes(vector<int>& nums) {
	for (int p = 0, zeroP = 0; p < nums.size(); p++)
		if (nums[p] != 0)
			swap(nums[zeroP++], nums[p]);
	return;
}

//290
bool Solution::wordPattern(string pattern, string str) {
	char c;
	string s;
	string::size_type p;
	map<char, int> pMap;
	map<string, int> sMap;

	if (pattern.empty() && str.empty()) return true;
	if (pattern.empty()) return false;

	for (auto it = pattern.begin(); it != pattern.end(); it++)
	{
		pMap[*it]++;
		if (str.empty()) return false;
		p = str.find(" ");
		s = str.substr(0, p);
		if (p == string::npos)
		{
			str.erase(str.begin(), str.end());
		}
		else
		{
			str.erase(str.begin(), str.begin() + p + 1);
		}
		sMap[s]++;
		if (pMap[*it] != sMap[s])
			return false;
	}
	if (!str.empty()) return false;
	return true;
}


//299
string Solution::getHint(string secret, string guess) {
	int bulls = 0, cows = 0;

	for (int i = 0; i < (int)guess.size(); i++)
	{
		if (guess[i] == secret[i])
		{
			bulls++;
			secret[i] = 'a';
			guess[i] = 'b';
		}
	}

	for (int i = 0; i < (int)guess.size(); i++)
	{
		string::size_type p = secret.find(guess[i]);
		if (p != string::npos)
		{
			cows++;
			secret.erase(p, 1);
		}
	}

	return to_string(bulls) + 'A' + to_string(cows) + 'B';
}

//303
void Solution::NumArray(vector<int> &nums) {
	if (nums.size() == 0) return;
	intNums[0] = nums[0];
	for (int i = 1; i < (int)nums.size(); i++)
		intNums.push_back(intNums[i - 1] + nums[i]);
}

int Solution::sumRange(int i, int j) {
	if (i == 0) return intNums[j];
	return intNums[j] - intNums[i - 1];
}

//219
bool Solution::containsNearbyDuplicate(vector<int>& nums, int k) {
	map<int, int> m;
	for (int i = 0; i < (int)nums.size(); i++)
		if ((m.insert(pair<int, int>(nums[i], i))).second == false)
			if ((i - m[nums[i]]) <= k)
				return true;
			else
				m[nums[i]] = i;
	return false;
}

//223
int Solution::computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
	int overlap = (min(C, G) - max(A, E))*(min(D, H) - max(B, F));
	if (min(C, G) <= max(A, E) || min(D, H) <= max(B, F))
		overlap = 0;
	return (C - A)*(D - B) + (G - E)*(H - F) - overlap;
}

//225
// Push element x onto stack.
void Solution::push(int x) {
	if (q1.empty())
	{
		q1.push(x);
		while (!q2.empty())
		{
			q1.push(q2.front());
			q2.pop();
		}
	}
	else
	{
		q2.push(x);
		while (!q1.empty())
		{
			q2.push(q1.front());
			q1.pop();
		}
	}
}

// Removes the element on top of the stack.
void Solution::pop() {
	if (q1.empty())
		q2.pop();
	else
		q1.pop();
}

// Get the top element.
int Solution::top() {
	if (q1.empty())
		return q2.front();
	else
		return q1.front();
}

// Return whether the stack is empty.
bool Solution::empty() {
	return q1.empty() && q2.empty();
}

//232. Implement Queue using Stacks

//234
bool Solution::isPalindrome(ListNode* head) {
	if (!head || !head->next) return true;
	ListNode* first = head;
	ListNode* mid = partition(head);
	mid = reverse(mid);
	while (mid)
	{
		if (mid->val != first->val)
			return false;
		mid = mid->next;
		first = first->next;
	}
	return true;
}

Solution::ListNode* Solution::partition(ListNode* head)
{
	int i = 0;
	ListNode* tmpL = head;
	while (tmpL)
	{
		i++;
		tmpL = tmpL->next;
	}
	for (int j = 0; j < (int)i / 2; j++)
		head = head->next;
	if (i % 2)
		return head->next;
	else
		return head;
}

Solution::ListNode* Solution::reverse(ListNode* head)
{
	ListNode* pre = nullptr;
	while (head)
	{
		ListNode* tmpL = head->next;
		head->next = pre;
		pre = head;
		head = tmpL;
	}
	return pre;
}

// 235
Solution::TreeNode* Solution::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (root == nullptr || p == nullptr || q == nullptr) return nullptr;
	if (max(p->val, q->val) < root->val)
		return lowestCommonAncestor(root->left, p, q);
	else if (min(p->val, q->val) > root->val)
		return lowestCommonAncestor(root->right, p, q);
	else
		return root;
}

//236
void Solution::l236()
{
	ptrTreeNode = new TreeNode;
	ptrTreeNode->val = 1;
	ptrTreeNode->left = nullptr;
	ptrTreeNode->right = new TreeNode;
	ptrTreeNode->right->val = 2;
	ptrTreeNode->right->left = nullptr;
	ptrTreeNode->right->right = nullptr;
	lowestCommonAncestor_236(ptrTreeNode, ptrTreeNode, ptrTreeNode->right);
}
Solution::TreeNode* Solution::lowestCommonAncestor_236(TreeNode* root, TreeNode* p, TreeNode* q) {
	vector<TreeNode*> pathP, pathQ;
	TreeNode* res = nullptr;
	if (root == nullptr || p == nullptr || q == nullptr) return nullptr;

	pathP.push_back(root);
	pathQ.push_back(root);

	if (!getPath(root, p, pathP)) return nullptr;
	if (!getPath(root, q, pathQ)) return nullptr;

	for (int i = 0; i < (int)min(pathP.size(), pathQ.size()); i++)
	{
		if (pathP[i] == pathQ[i])
			res = pathP[i];
		else
			break;
	}
	return res;
}

bool Solution::getPath(TreeNode* root, TreeNode* t, vector<TreeNode*>& path)
{
	if (root == t) return true;

	if (root->left)
	{
		path.push_back((root->left));
		if (getPath(root->left, t, path)) return true;
		path.pop_back();
	}
	if (root->right)
	{
		path.push_back((root->right));
		if (getPath(root->right, t, path)) return true;
		path.pop_back();
	}
	return false;
}

//237
void Solution::deleteNode(ListNode* node) {
	if (node->next == nullptr) return;
	ListNode* pre = nullptr;
	while (node->next != nullptr)
	{
		pre = node;
		node->val = node->next->val;
		node = node->next;
	}
	pre->next = nullptr;
}

//6
string Solution::convert(string s, int numRows) {
	if ((int)s.size() <= numRows) return s;
	if ((int)s.size() == 0 || numRows == 1) return s;

	string res;
	int lag = 2 * numRows - 2;

	for (int i = 0; i < numRows; i++)
	{
		for (int j = i; j < (int)s.size(); j += lag)
		{
			res += s[j];
			if ((i > 0) && (i < (numRows - 1)))
				if ((j + lag - 2 * i) < (int)s.size())
					res += s[j + lag - 2 * i];
		}
	}
	return res;
}

//7
int Solution::reverse(int x) {
	string res;
	res = to_string(abs(x));
	std::reverse(res.begin(), res.end());
	double i = stod(res);
	if (x < 0)
		i = -i;

	if ((i > INT_MAX) || (i < INT_MIN))
		return 0;

	return int(i);
}

// 9
bool Solution::isPalindrome(int x) {
	if (x < 0) return false;

	int div = 1;
	while (x / div >= 10)
		div *= 10;

	while (x != 0)
	{
		if ((x / div) != (x % 10)) return false;
		x = (x % div) / 10;
		div /= 100;
	}
	return true;
}

// 13
int Solution::romanToInt(string s) {
	int res = 0;
	map<char, int> tmpM = { { 'I',1 },{ 'V', 5 },{ 'X', 10 },{ 'L', 50 },{ 'C', 100 },{ 'D', 500 },{ 'M', 1000 } };

	for (int i = 0; i < (int)s.size(); i++)
	{
		res += tmpM[s[i]];
		if ((i > 0) && (tmpM[s[i - 1]] < tmpM[s[i]]))
			res -= 2 * tmpM[s[i - 1]];
	}
	return res;
}

// 14
string Solution::longestCommonPrefix(vector<string>& strs) {
string prefix="";
if(strs.empty())  return prefix;

// check char by char, for each char, check all the string word 
for (int k = 0; k < strs[0].size(); k++) {
	for (int i = 1; i<strs.size(); i++)
		if (strs[i].size() <= k || strs[i][k] != strs[0][k])
			return prefix;
	prefix += strs[0][k];
}
return prefix;
}

//19
Solution::ListNode* Solution::removeNthFromEnd(ListNode* head, int n) {
	if (head == nullptr) return nullptr;

	ListNode* tmpPtr = head;
	int sum = 0;
	while (tmpPtr != nullptr)
	{
		sum++;
		tmpPtr = tmpPtr->next;
	}
	if (sum < n) return nullptr;
	if (sum == n) return head->next;
	tmpPtr = head;

	int i = 1;
	while (tmpPtr != nullptr)
	{
		if (i == (sum - n))
			tmpPtr->next = tmpPtr->next->next;
		tmpPtr = tmpPtr->next;
		i++;
	}
	return head;
}

//20
bool Solution::isValid(string s) {
	stack<char> tmpS;
	for (int i = 0; i < (int)s.size(); i++)
	{
		if ((s[i] == '(') || (s[i] == '{') || (s[i] == '['))
		{
			tmpS.push(s[i]);
		}
		else
		{
			if (tmpS.empty()) return false;
			char tmp = tmpS.top();
			if ((tmp == '(' && s[i] == ')') || (tmp == '{' && s[i] == '}') || (tmp == '[' && s[i] == ']'))
				tmpS.pop();
			else
				return false;
		}
	}
	return tmpS.empty();
}

//21
Solution::ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode dummy(0);
	ListNode *cur = &dummy;

	while(l1 != nullptr && l2 != nullptr) {
		if(l1->val < l2->val) {
			cur->next = l1;
			l1 = l1->next;
		}
		else {
			cur->next = l2;
			l2 = l2->next;
		}
		cur = cur->next;
	}

	cur->next = l1 == nullptr? l2:l1;

	return dummy.next;
}


//26. Remove Duplicates from Sorted Array Add to List
int Solution::removeDuplicates(vector<int>& nums) {
	int n = nums.size(), pos = 1;
	if(n == 0)
	return 0;
	for(int i = 1; i < n; i++)
		if(nums[i] > nums[i-1])
			nums[pos++] = nums[i];

	return pos;
}

//27
int Solution::removeElement(vector<int>& nums, int val) {
	if (nums.size() == 0) return 0;
	int j = nums.size();
	for (int i = 0; i < j; i++)
	{
		if (nums[i] == val)
		{
			nums.erase(nums.begin() + i);
			i--;
			j--;
		}
	}
	return nums.size();
}

//28
int Solution::strStr(string haystack, string needle) {
	int m = haystack.size();
	int n = needle.size();
	for (int i = 0; i <= m - n; i++)
		if (haystack.compare(i, n, needle) == 0)
			return i;
	return -1;

	/* Rabin–Karp algorithm
	doesn't work. must implement your own hash function.
	// ASCII a = 97, b = 98, r = 114.
	hash("abr") = (97 × pow(101, 2) + (98 × pow(101,1) + (114 × pow(101, 0)) = 999,509
	//             base   old hash    old 'a'         new 'a'
	hash("bra") = [pow(101, 1) × (999,509 - (97 × pow(101, 2))] + (97 × pow(101 ,0)) = 1,011,309

	hash<string> myHash;
	long long target = myHash(needle), source = 0;
	int m = haystack.size(), n = needle.size();
	for(int i = 0; i <= m - n; i++) {
	source = i == 0 ? myHash(haystack.substr(i, n)) : source + myHash(haystack.substr(i+n, 1)) - myHash(haystack.substr(i - 1, 1));
	if(source == target) {
	if(haystack.compare(i, n, needle) == 0) {
	return i;
	}
	}
	}

	return -1;
	
	}

//205
bool Solution::isIsomorphic(string s, string t) {
	int m = s.size();
	if (m != t.size()) return false;

	map<char, char> st; // s-->t
	map<char, char> ts; // t-->s

	for (int i = 0; i < m; i++)
	{
		if (((st.insert(pair<char, char>(s[i], t[i]))).second == false) && (st[s[i]] != t[i]))
			return false;
		if (((ts.insert(pair<char, char>(t[i], s[i]))).second == false) && (ts[t[i]] != s[i]))
			return false;
	}

	return true;
}

//203
Solution::ListNode* Solution::removeElements(ListNode* head, int val) {
	if (head == nullptr) return nullptr;

	if (head->val == val)
		while (head != nullptr && head->val == val)
			head = head->next;
	if (head == nullptr) return nullptr;

	ListNode* prePtr = head;
	ListNode* ptr = head->next;

	while (ptr != nullptr)
	{
		if (ptr->val == val)
			prePtr->next = ptr->next;
		else
			prePtr = prePtr->next;
		ptr = ptr->next;
	}
	return head;
}

//172
int Solution::trailingZeroes(int n) {
	int res = 0;
	while ((n = n / 5) > 0)
		res += n;
	return res;
}

//204
int Solution::countPrimes(int n) {
	vector<bool> tmpV(n + 1);

	for (int i = 3; i <= n; i++)
	{
		if (i % 2 == 0) tmpV[i] = false;
		else tmpV[i] = true;
	}
	tmpV[2] = true;

	for (int i = 3; i * i <= n; i += 2)
	{
		if (tmpV[i])
		{
			for (int j = 2; i * j <= n; j++)
				tmpV[i*j] = false;
		}
	}

	int res = 0;
	for (int i = 2; i < n; i++)
		if (tmpV[i]) res++;

	return res;
}

//202
bool Solution::isHappy(int n) {
	unordered_set<int> numbers;
	unsigned long sum = 0, m = n;
	while(sum <= ULONG_MAX) {
		sum = 0;
		while(m > 0) {
			sum += (m % 10) * (m % 10);
			m /= 10;
		}
		if(sum == 1)
			return true;
		if(numbers.insert(sum).second == false)
			return false;
		m = sum;
	}

}

//198
int Solution::rob(vector<int>& nums) {
	int len = nums.size();
	if (len == 0) return 0;
	if (len == 1) return nums[0];
	if (len == 2) return max(nums[0], nums[1]);

	vector<int> sum(len);
	sum[0] = nums[0];
	sum[1] = max(nums[0], nums[1]);
	for (int i = 2; i < len; i++)
		sum[i] = max(sum[i - 1], sum[i - 2] + nums[i]);
	return sum[len - 1];
}
*/

//190
uint32_t Solution::reverseBits(uint32_t n) {
	int res = 0;
	for (int i = 0; i < 32; i++)
		res += (((n >> i) & 1) << (31 - i));
	return res;
}

//171
int Solution::titleToNumber(string s) {
	int res = 0;
	for (int i = (int)s.size() - 1; i >= 0; i--)
		res += (s[i] - 'A' + 1) * (int)pow(26, s.size() - 1 - i);

	return res;
}

//169
int Solution::majorityElement(vector<int>& nums) {
	map<int, int> m;
	int n = (int)nums.size();

	for (int i = 0; i < n; i++)
	{
		if ((m.insert(pair<int, int>(nums[i], 1))).second == false)
			m[nums[i]]++;
		if (m[nums[i]] > n / 2) return nums[i];
	}
	return 0;
}

//168
string Solution::convertToTitle(int n) {
	string tmpS = "ABCDEFGHIJKLMNOPQRSGUVWXYZ";
	string res;
	while (n)
	{
		res = tmpS[(n - 1) % 26] + res;
		n = (n - 1) / 26;
	}
	return res;
}

//160
Solution::ListNode* Solution::getIntersectionNode(ListNode* headA, ListNode* headB)
{
	ListNode *cur1 = headA, *cur2 = headB;
	while (cur1 != cur2) {
		cur1 = cur1 ? cur1->next : headB;
		cur2 = cur2 ? cur2->next : headA;
	}
	return cur1;
}

//141
bool Solution::hasCycle(ListNode *head) {
	ListNode* slow = head;
	ListNode* fast = head;

	while (slow != nullptr && fast != nullptr && fast->next != nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return true;
	}
	return false;
}

//119
vector<int> Solution::getRow(int rowIndex) {
	rowIndex++;
	vector<int> res(rowIndex);
	if (rowIndex <= 1) return{ 1 };
	if (rowIndex == 2) return{ 1,1 };

	res[0] = 1;
	for (int j = 1; j <= rowIndex - 2; j++)
	{
		res[j] = (int)((rowIndex - j) * (double)res[j - 1] / j);
	}
	res[rowIndex - 1] = 1;

	return res;
}

//118
vector<vector<int>> Solution::generate(int numRows) {
	vector<vector<int>> res(abs(numRows));
	if (numRows < 1) return res;
	res[0] = { 1 };
	if (numRows == 1) return res;
	res[1] = { 1,1 };
	if (numRows == 2) return res;

	for (int i = 3; i <= numRows; i++)
	{
		int n = 0;
		res[i - 1].push_back(1);
		for (int j = 1; j <= i - 2; j++)
		{
			n = (int)(((double)(i - j) * (double)res[i - 1][j - 1]) / (double)j);
			res[i - 1].push_back(n);
		}
		res[i - 1].push_back(1);
	}
	return res;
}

//58 test case -> " a  b   ";
int Solution::lengthOfLastWord(string s) {
	int pos = -1;
	int n = (int)s.size();
	while (s[n - 1] == ' ')
	{
		s.pop_back();
		n = n - 1;
	}

	n = (int)s.size();
	for (int i = 0; i < n; i++)
		if (s[i] == ' ') pos = i;
	if (pos < 0)
		return (int)s.size();
	else
		return (int)s.size() - (pos + 1);
}

//66
vector<int> Solution::plusOne(vector<int>& digits) {
	int m = (int)digits.size();
	vector<int> res(m + 1);
	res[0] = 0;
	int carry = 0;
	int add = 1;

	for (int i = m - 1; i >= 0; i--)
	{
		if (digits[i] + carry + add == 10)
		{
			res[i + 1] = 0;
			carry = 1;
		}
		else
		{
			res[i + 1] = digits[i] + add + carry;
			carry = 0;
		}
		if (carry == 1 && i == 0)
			res[0] = 1;

		add = 0;
	}
	if (res[0] == 0) res.erase(res.begin());
	return res;
}


//67
string Solution::addBinary(string a, string b) {
	if (a.size() < b.size()) a.swap(b);
	int m = (int)a.size();
	int n = (int)b.size();
	if (m == 0) return b;
	if (n == 0) return a;
	string res;
	int carry = 0;
	for (int i = n - 1, j = m - 1; i >= 0; i--, j--)
	{
		int k = a[j] + b[i] - '0' - '0';
		if (k == 0)
		{
			if (carry)
			{
				res = '1' + res;
				carry--;
			}
			else
			{
				res = '0' + res;
			}
		}
		else if (k == 1)
		{
			if (carry)
			{
				res = '0' + res;
			}
			else
			{
				res = '1' + res;
			}
		}
		else if (k == 2)
		{
			if (carry)
			{
				res = '1' + res;
				carry--;
			}
			else
			{
				res = '0' + res;
			}
			carry++;
		}
	}
	for (int j = m - n - 1; j >= 0; j--)
	{
		if (carry > 0)
		{
			if (a[j] == '0')
			{
				res = '1' + res;
				carry--;
			}
			else
			{
				res = '0' + res;
			}
		}
		else
		{
			res = a[j] + res;
		}
	}
	while (carry > 0)
	{
		res = "1" + res;
		carry--;
	}
	return res;
}

//88. Merge Sorted Array
void Solution::merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int tar = m + n - 1, i = m - 1, j = n - 1;
	while (j >= 0)
		nums1[tar--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
}

//100. Same Tree
bool Solution::isSameTree(TreeNode* p, TreeNode* q) {
	if (p == nullptr && q == nullptr)
		return true;
	if (p == nullptr || q == nullptr)
		return false;
	if (p->val != q->val) return false;
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

//101. Symmetric Tree
bool Solution::isSymmetric(TreeNode* root) {
	if (root == nullptr) return true;
	return isSymmetric(root->left, root->right);
}
bool Solution::isSymmetric(TreeNode* left, TreeNode* right) {
	if (left == nullptr && right == nullptr) return true;
	if (left == nullptr || right == nullptr || left->val != right->val) return false;
	return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
}

//102. Binary Tree Level Order Traversal
vector<vector<int>> Solution::levelOrder(TreeNode* root) {
	vector<vector<int>> res;
	levelOrder(root, 0, res);
	return res;

	//107. Binary Tree Level Order Traversal II
	//return vector<vector<int>>(res.rbegin(), res.rend());
}
void Solution::levelOrder(TreeNode* root, int depth, vector<vector<int>>& v)
{
	if (root == nullptr) return;
	if (depth == v.size()) v.push_back(vector<int>());
	v[depth].push_back(root->val);
	levelOrder(root->left, depth + 1, v);
	levelOrder(root->right, depth + 1, v);
	return;
}

//111. Minimum Depth of Binary Tree
int Solution::minDepth(TreeNode* root) {
/*
if (root == NULL) return 0;
queue<TreeNode*> Q;
Q.push(root);
int i = 0;
while (!Q.empty()) {
i++;
int k = Q.size();
for (int j=0; j<k; j++) {
TreeNode* rt = Q.front();
if (rt->left) Q.push(rt->left);
if (rt->right) Q.push(rt->right);
Q.pop();
if (rt->left==NULL && rt->right==NULL) return i;
}
}
return -1; //For the compiler thing. The code never runs here.
*/

	if (root == nullptr)
		return 0;
	else
		return minDepth(root, 1);
}
int Solution::minDepth(TreeNode* root, int depth)
{
	if (root->left == nullptr && root->right == nullptr)
		return depth;
	else if (root->left == nullptr)
		return minDepth(root->right, depth + 1);
	else if (root->right == nullptr)
		return minDepth(root->left, depth + 1);
	else
		return min(minDepth(root->left, depth + 1), minDepth(root->right, depth + 1));
}

//110. Balanced Binary Tree
int Solution::height(TreeNode* root) {
	if (root == NULL)
		return 0;
	else {
		int l = height(root->left);
		int r = height(root->right);
		return 1 + ((l>r) ? l : r);
	}
}
bool Solution::isBalanced(TreeNode *root) {
	if (root == NULL)
		return true;
	else {
		int l, r;
		l = height(root->left);
		r = height(root->right);
		if ((l > r + 1) || (r > l + 1))
			return false;
		else
			return isBalanced(root->left) && isBalanced(root->right);
	}
}

//136. Single Number
int Solution::singleNumber(vector<int>& nums) {
	map<int, int> m;
	for (int i = 0; i < (int)nums.size(); i++)
		if ((m.insert(pair<int, int>(nums[i], 1))).second == false)
			m[nums[i]]++;
	for (auto it = m.begin(); it != m.end(); it++)
		if (it->second == 1) return it->first;
	return 0;
}

//121. Best Time to Buy and Sell Stock
int Solution::maxProfit(vector<int>& prices) {
	if (prices.size() < 2) return 0;

	int prePrice = prices[0];
	int MaxPro = 0;
	for (int i = 1; i < (int)prices.size(); i++)
	{
		prePrice = min(prePrice, prices[i - 1]);
		if (MaxPro < prices[i] - prePrice)
		    MaxPro = prices[i] - prePrice;
	}

	return MaxPro;
}

//123. Best Time to Buy and Sell Stock III
int Solution::maxProfit123(vector<int>& prices) {
	int n = (int)prices.size();
	vector<int> first(n, 0);
	vector<int> second(n, 0);

	int maxProfit = 0;
	int minPrice = prices[0];
	for (int i = 0; i < n; i++)
	{
		minPrice = min(minPrice, prices[i]);
		if (maxProfit < prices[i] - minPrice) maxProfit = prices[i] - minPrice;
		first[i] = maxProfit;
	}

	int maxPrice = -1;
	maxProfit = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		maxPrice = max(maxPrice, prices[i]);
		if (maxProfit < maxPrice - prices[i]) maxProfit = maxPrice - prices[i];
		second[i] = maxProfit;
	}

	maxProfit = 0;
	for (int i = 0; i < n; i++)
	{
		if (maxProfit < first[i] + second[i])
			maxProfit = first[i] + second[i];
	}

	return maxProfit;
}

//38. Count and Say
string Solution::countAndSay(int n) {
	if (n < 1) return "";
	string res = "1";

	for (int i = 1; i < n; i++)
	{
		int count = 1;
		string tmp;
		for (int j = 0; j < (int)res.size(); j++)
		{
			if ((j + 1) < (int)res.size() && res[j] == res[j + 1])
				count++;
			else
			{
				tmp = tmp + to_string(count) + res[j];
				count = 1;
			}
		}

		tmp.swap(res);
	}

	return res;
}

//376. Wiggle Subsequence
int Solution::wiggleMaxLength376(vector<int>& nums) {
	int n = (int)nums.size();
	if (n < 2) return n;

	int preDif, dif;
	int len;

	preDif = nums[1] - nums[0];

	len = (preDif == 0) ? 1 : 2;

	for (int i = 2; i < n; i++)
	{
		dif = nums[i] - nums[i - 1];

		if ((preDif >= 0 && dif < 0) || (preDif <= 0 && dif > 0))
		{
			len++;
			preDif = dif;
		}
	}

	return len;
}

//113. Path Sum II
vector<vector<int>> Solution::pathSum(TreeNode* root, int sum) {
	vector<vector<int>> res;
	vector<int> path;

	pathSum(root, sum, res, path);

	return res;
}
void Solution::pathSum(TreeNode* root, int sum, vector<vector<int>>& res, vector<int> path)
{
	if (!root)
		return;

	path.push_back(root->val);
	if (!root->left && !root->right && root->val == sum)
	{
		res.push_back(path);
		return;
	}
	if (root->left)
		pathSum(root->left, sum - root->val, res, path);
	if (root->right)
		pathSum(root->right, sum - root->val, res, path);

	return;
}

void Solution::testVector(vector<int>& v)
{
	TreeNode* tmp = new TreeNode(100);
//	TreeNode** tmpPtrPtr = new TreeNode*[10]();

	v.push_back(100);
}
void Solution::testVector(vector<int> v,int i)
{
	v.push_back(200);
}

//108. Convert Sorted Array to Binary Search Tree
Solution::TreeNode* Solution::sortedArrayToBST(vector<int>& nums) {
	return sortedArrayToBST(0, (int)nums.size() - 1, nums);
}

Solution::TreeNode* Solution::sortedArrayToBST(int left, int right, vector<int>& nums)
{
	if (left > right)
		return nullptr;
	else if (left == right)
	{
		return new TreeNode(nums[left]);
	}
	else
	{
		int mid = (left + right) / 2;
		TreeNode* node = new TreeNode(nums[mid]);

		node->left = sortedArrayToBST(left, mid - 1, nums);
		node->right = sortedArrayToBST(mid + 1, right, nums);

		return node;
	}
}

//144. Binary Tree Preorder Traversal
vector<int> Solution::preorderTraversal(TreeNode* root)
{
	vector<int> res;
	stack<TreeNode*> tmpS;

	while (!tmpS.empty() || root != nullptr)
	{
		if (root != nullptr)
		{
			if(root->right)
				tmpS.push(root->right);
			res.push_back(root->val);
			root = root->left;
		}
		else
		{
			root = tmpS.top();
			tmpS.pop();
		}
	}

	return res;
}

//94. Binary Tree Inorder Traversal
vector<int> Solution::inorderTraversal(TreeNode* root)
{
	vector<int> res;
	stack<TreeNode*> tmpS;

	while (!tmpS.empty() || root != nullptr)
	{
		if (root != nullptr)
		{
			tmpS.push(root);
			root = root->left;
		}
		else
		{
			root = tmpS.top();
			tmpS.pop();
			res.push_back(root->val);
			root = root->right;
		}
	}

	return res;
}
//145. Binary Tree Postorder Traversal 
//对于每个节点，都压入两遍，在循环体中，每次弹出一个节点赋给p，如果p仍然等于栈的头结点，说明p的孩子们还没有被操作过，
//应该把它的孩子们加入栈中，否则，访问p。也就是说，第一次弹出，将p的孩子压入栈中，第二次弹出，访问p
vector<int> Solution::postorderTraversal(TreeNode* root) {
	if (root == nullptr) return vector<int>();

	vector<int> res;
	stack<TreeNode*> tmpS;

	TreeNode* p = root;
	tmpS.push(p);
	tmpS.push(p);

	while (!tmpS.empty())
	{
		p = tmpS.top();
		tmpS.pop();
		if (!tmpS.empty() && p == tmpS.top())
		{
			if (p->right)
			{
				tmpS.push(p->right);
				tmpS.push(p->right);
			}
			if (p->left)
			{
				tmpS.push(p->left);
				tmpS.push(p->left);
			}
		}
		else
		{
			res.push_back(p->val);
		}
	}

	return res;
}

//105. Construct Binary Tree from Preorder and Inorder Traversal
Solution::TreeNode* Solution::buildTree105(vector<int>& preorder, vector<int>& inorder) {
	return buildTree105(preorder, 0, (int)preorder.size() - 1, inorder, 0, (int)inorder.size() - 1);
}

Solution::TreeNode* Solution::buildTree105(vector<int>& preorder, int begin1, int end1, vector<int>& inorder, int begin2, int end2) 
{
	if (begin1 > end1)
		return nullptr;
	else if (begin1 == end1)
		return new TreeNode(preorder[begin1]);

	int i = begin2;
	for (; i <= end2; i++)
	{
		if (preorder[begin1] == inorder[i])
			break;
	}

	int len = i - begin2;

	TreeNode* node = new TreeNode(preorder[begin1]);
	node->left = buildTree105(preorder, begin1 + 1, begin1 + len, inorder, begin2, begin2 + len - 1);
	node->right = buildTree105(preorder, begin1 + len + 1, end1, inorder, begin2 + len + 1, end2);

	return node;
}

//106. Construct Binary Tree from Inorder and Postorder Traversal
Solution::TreeNode* Solution::buildTree(vector<int>& inorder, vector<int>& postorder) {
	return buildTree(inorder, 0, (int)inorder.size() - 1, postorder, 0, (int)postorder.size() - 1);
}

Solution::TreeNode* Solution::buildTree(vector<int>& inorder, int begin1, int end1, vector<int>& postorder, int begin2, int end2)
{
	if (begin2 > end2)
		return nullptr;
	else if (begin2 == end2)
		return new TreeNode(postorder[end2]);
	else
	{
		TreeNode * node = new TreeNode(postorder[end2]);
		int i = begin1;
		for (; i <= end1; i++)
		{
			if (inorder[i] == postorder[end2])
				break;
		}
		int len = i - begin1;
		node->left = buildTree(inorder, begin1, begin1 + len - 1, postorder, begin2, begin2 + len - 1);
		node->right = buildTree(inorder, begin1 + len + 1, end1, postorder, begin2 + len, end2 - 1);
		return node;
	}
}

//一个背包的题目，背包容量为数组中元素和的一半＋１，这样只要看是否有元素可以正好填满背包即可．
//但是每个元素只能用一次，所以在尝试放一个元素的时候还要避免他对尝试放其他位置时对自己的影响．
//所以在尝试放一个元素到背包的时候需要从容量最大的位置开始，如果（当前位置－当前元素大小）位置可以通过放置之前的元素达到，
//则当前位置也可以通过放置当前元素正好达到这个位置．状态转移方程为：dp[i] = dp[i] || dp[i - nums[k]]
//416. Partition Equal Subset Sum
bool Solution::canPartition(vector<int>& nums) {
	int sum = 0;
	for (int i : nums)
		sum += i;

	if (sum % 2)
		return false;

	int len = sum / 2;
	vector<bool> dp(len + 1, false);

	dp[0] = true;
	for (int i = 0; i < (int)nums.size(); i++)
		for (int j = len; j >= nums[i]; j--)
			if (dp[j - nums[i]])
				dp[j] = true;

	return dp[len];
}

//415. Add Strings
string Solution::addStrings(string num1, string num2) {
	if (num1.size() < num2.size())
		num1.swap(num2);

	if (num2.size() == 0) return num1;

	int m = (int)num1.size();
	int n = (int)num2.size();

	int carry = 0;

	for (int i = n - 1; i >= 0; i--)
	{
		int k = num1[m - n + i] + num2[i] - '0' - '0';
		if (carry)
		{
			k++;
			carry--;
		}
		if (k / 10)
		{
			k = k % 10;
			carry++;
		}
		num1[m - n + i] = k + '0';
	}

	if (carry)
	{
		for (int i = m - n - 1; i >= 0; i--)
		{
			if (carry)
			{
				int k = num1[i] + carry - '0';
				carry--;
				if (k / 10)
				{
					k = k % 10;
					carry++;
				}
				num1[i] = k + '0';
			}
		}
	}

	if (carry)
		num1 = "1" + num1;

	return num1;
}

//410. Split Array Largest Sum
int Solution::splitArray(vector<int>& nums, int m) 
{
		long long left = 0, right = 0;
		for (int num : nums)
		{
			left = max(left, (long long)num);
			right += num;
		}

		while (left < right)
		{
			int mid = (int)(left + (right - left) / 2);
			if (splitable(nums, m, mid))
				right = mid;
			else
				left = mid + 1;
		}

		return (int)left;
}

bool Solution::splitable(vector<int>& nums, int m, int largestSum)
{
		long long sum = 0;
		for (int num : nums)
		{
			if ((sum + num) <= largestSum) sum += num;
			else
			{
				m--;
				if (m < 1)
					return false;
				sum = num;
			}
		}

		return true;
}
/*
//406. Queue Reconstruction by Height
vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {

}
*/

//vm ware pracice, flip 0 and 1
pair<int, int> Solution::VMWareFlip(string s)
{
	int i = 0, j = 0;
	int maxSum = 0, countZero = 0;
	pair<int, int> res;
	for (; i < (int)s.size(); i++)
	{
		if (s[i] == '0')
			countZero++;
		else
			countZero--;
		if (countZero < 0)
		{
			j = i + 1;
			countZero = 0;
		}
		else if (countZero > maxSum)
		{
			maxSum = countZero;
		    res = pair<int, int>(j, i);
		}
	}
	return res;
}

//315. Count of Smaller Numbers After Self
vector<int> Solution::countSmaller(vector<int>& nums) {
	BST* root = nullptr;
	vector<int> res(nums.size());
	for (int i = (int)nums.size() - 1; i >= 0; i--)
		res[i] = insertBST(root, nums[i]);
	return res;
}

int Solution::insertBST(BST* &root, int value) {
	if (root == nullptr) {
		root = new BST(value, 0);
		return 0;
	}
	else if (value < root->val) {
		root->smaller++;
		return insertBST(root->left, value);
	}
	else {
		int k = (value > root->val) ? 1 : 0;
		return insertBST(root->right, value) + root->smaller + k;
	}
}

//1 Two Sum
vector<int> Solution::twoSum_I(vector<int>& nums, int target) {

	unordered_map<int, int> hashmap;

	for (int i = 0; i < (int)nums.size(); i++) {
		int dif = target - nums[i];
		if (hashmap.find(dif) != hashmap.end()) {
			return vector<int>{hashmap[dif], i};
		}
		hashmap[nums[i]] = i;
	}

	return vector<int>{-1, -1};
/*
	unordered_map<int, int> hash;
	vector<int> ans;

	for (int i = 0; i < (int)nums.size(); i++) {
		int tmp = target - nums[i];
		if (hash.find(tmp) != hash.end()) {
			ans.push_back(i);
			ans.push_back(hash[tmp]);

			return ans;
		}

		hash[nums[i]] = i;
	}

	return ans;
*/
}


//170. Two Sum III - Data structure design
void Solution::add(int number) {
	nums_170.insert(number);
}

// Find if there exists any pair of numbers which sum is equal to the value.
bool Solution::find(int value) {
	for (int num : nums_170) {
		int tmp = value - num;
		int count = (tmp == num) ? 1 : 0;
		if ((int)nums_170.count(tmp) > count)
			return true;
	}
	return false;
}

//167. Two Sum II - Input array is sorted  
vector<int> Solution::twoSum(vector<int>& numbers, int target) {
	int l = 0;
	int r = (int)numbers.size() - 1;
	while (l < r) {
		if (numbers[l] + numbers[r] == target) {
			vector<int> res{ l + 1,r + 1 };
			return res;
		}
		else if (numbers[l] + numbers[r] > target) {
			r--;
		}
		else {
			l++;
		}
	}
	vector<int> res{ -1, -1 };
	return res;
}

//2. Add Two Numbers 
Solution::ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode dummy(0), *cur = &dummy;
	int sum = 0, carry = 0;
	while (l1 || l2 || carry) {
		sum = carry;
		if (l1) {
			sum += l1->val;
			l1 = l1->next;
		}
		if (l2) {
			sum += l2->val;
			l2 = l2->next;
		}

		carry = sum / 10;
		sum = sum % 10;

		cur->next = new ListNode(sum);
		cur = cur->next;
	}

	return dummy.next;
}

//151. Reverse Words in a String
void Solution::reverseWords(string &s) {


	reverse(s.begin(), s.end());
	int storeIndex = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] != ' ') {
			if (storeIndex != 0) s[storeIndex++] = ' ';
			int j = i;
			while (j < (int)s.size() && s[j] != ' ') { s[storeIndex++] = s[j++]; }
			reverse(s.begin() + storeIndex - (j - i), s.begin() + storeIndex);
			i = j;
		}
	}
	s.erase(s.begin() + storeIndex, s.end());
}

//414. Third Maximum Number

int Solution::thirdMax(vector<int>& nums) {
	set<int> top3;
	for (auto n : nums) {
		top3.insert(n);
		if (top3.size() > 3)
			top3.erase(top3.begin());
	}

	return top3.size() == 3 ? *top3.begin() : *top3.rbegin();
}

//3. Longest Substring Without Repeating Characters
int Solution::lengthOfLongestSubstring(string s) {
	vector<int> dict(128, 0);
	int start = 0, end = 0, len = 0, count = 0;

	while (end < (int)s.size()) {
		if (dict[s[end]] > 0)
			count++;

		dict[s[end]]++;
		end++;

		while (count > 0) {
			if (dict[s[start]] > 1)
				count--;
			dict[s[start]]--;
			start++;
		}

		len = max(len, end - start);
	}

	return len;

/*
	vector<int> dict(256, -1);
	int maxLen = 0, start = -1;
	for (int i = 0; i < (int)s.size(); i++) {
		if (dict[s[i]] > start)
			start = dict[s[i]];
		dict[s[i]] = i;
		maxLen = max(maxLen, i - start);
	}

	return maxLen;
*/
/*
	unordered_map<char, int> charMap;
	int maxLen = 0, i, j;
	for (i = 0, j = 0; j<(int)s.size(); j++) {
		//Update left pointer and update maxLen
		if (charMap.find(s[j]) != charMap.end() && charMap[s[j]] >= i) {
			maxLen = maxLen >(j - i) ? maxLen : (j - i);
			i = charMap[s[j]] + 1;
		}

		charMap[s[j]] = j;
	}

	return maxLen > (j - i) ? maxLen : (j - i);
*/
}

//5. Longest Palindromic Substring
string Solution::longestPalindrome(string s) {
	int len = (int)s.size();
	if (len < 2) return s;

	int minPos = 0, maxLen = 1;

	for (int i = 0; i < len; ) {
		int j = i, k = i;
		while (k < len - 1 && s[k] == s[k + 1])
			k++;
		i = k + 1;
		while (k < len - 1 && j > 0 && s[k + 1] == s[j - 1]) {
			k++;
			j--;
		}

		int newLen = k - j + 1;
		if (newLen > maxLen) {
			minPos = j;
			maxLen = newLen;
		}
	}
	return s.substr(minPos, maxLen);
}

//15. 3Sum 
vector<vector<int>> Solution::threeSum(vector<int>& nums) {
	vector<vector<int>> triples;
	sort(nums.begin(), nums.end());
	int i = 0, last = (int)nums.size() - 1;
	while (i < last) {
		int a = nums[i], j = i + 1, k = last;
		while (j < k) {
			int b = nums[j], c = nums[k], sum = a + b + c;
			if (sum == 0) triples.push_back({ a, b, c });
			if (sum <= 0) while (nums[j] == b && j < k) j++;
			if (sum >= 0) while (nums[k] == c && j < k) k--;
		}
		while (nums[i] == a && i < last) i++;
	}
	return triples;
}

//18. 4Sum
vector<vector<int>> Solution::fourSum(vector<int>& nums, int target) {
	vector<vector<int>> res;
	int n = nums.size();
	if (n < 4) return res;

	sort(nums.begin(), nums.end());

	for (int i = 0; i < n - 3; i++) {
		if (i > 0 && nums[i] == nums[i - 1])
			continue;
		if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
			return res;
		else if (nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target)
			continue;

		for (int j = i + 1; j < n - 2; j++) {
			if (j > i + 1 && nums[j] == nums[j - 1]) continue;
			if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
				break;
			else if (nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target)
				continue;
			int left = j + 1, right = n - 1;
			while (left < right) {
				if (nums[i] + nums[j] + nums[left] + nums[right] == target) {
					res.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
					while (left < right && nums[left] == nums[left + 1])
						left++;
					while (left < right && nums[right] == nums[right - 1])
						right--;
					left++;
					right--;
				}
				else if (nums[i] + nums[j] + nums[left] + nums[right] < target)
					left++;
				else
					right--;
			}
		}
	}
	return res;
}

//433. Minimum Genetic Mutation
int Solution::minMutation(string start, string end, vector<string>& bank) {
	list<mutation> tmpS;
	mutation tmpM(start, 0);
	queue<mutation> tmpQ;

	tmpQ.push(tmpM);
	for (auto it = bank.begin(); it != bank.end(); it++) {
		tmpM.gen = *it;
		tmpM.depths = 0;
		tmpS.push_back(tmpM);
	}

	while (!tmpQ.empty()) {
		string str1 = tmpQ.front().gen;
		int steps = tmpQ.front().depths;
		tmpQ.pop();

		if (str1 == end) return steps;

		int size = tmpS.size();
		auto it = tmpS.begin();
		for (int i = 0; i < size; i++) {
			if (isMutation(str1, (*it).gen)) {
				(*it).depths = steps + 1;
				tmpQ.push(*it);
				it = tmpS.erase(it);
			}
			else
				it++;
		}
	}

	return -1;

}

bool Solution::isMutation(string m, string n) {
	int size = (int)m.size();
	if (size != n.size()) return false;

	int count = 0;
	for (int i = 0; i < size; i++) {
		if (m[i] != n[i]) {
			count++;
		}
	}
	return count == 1;
}

// Inserts a new key <Key> with value 1. Or increments an existing key by 1. 
void Solution::inc(string key) {
	if (mapOfKey.find(key) == mapOfKey.end()) {
		if (!buckets.empty() && buckets.begin()->val == 1) {
			buckets.begin()->keys.insert(key);
			mapOfKey[key] = buckets.begin();
		}
		else
			mapOfKey[key] = buckets.insert(buckets.begin(), { 1,{ key } });
	}
	else {
		auto curIt = mapOfKey[key];
		auto nextIt = curIt;
		nextIt++;
		if (nextIt != buckets.end() && (nextIt->val == curIt->val + 1)) {
			mapOfKey[key] = nextIt;
			nextIt->keys.insert(key);
		}
		else if (nextIt == buckets.end()) {
			buckets.push_back({ curIt->val + 1,{ key } });
			mapOfKey[key] = ++curIt;
			curIt--;
		}
		else {
			mapOfKey[key] = buckets.insert(nextIt, { curIt->val + 1, {key} });
		}
		curIt->keys.erase(key);
		if (curIt->keys.empty())
			buckets.erase(curIt);
	}

}

// Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. 
void Solution::dec(string key) {
	if (mapOfKey.find(key) == mapOfKey.end())
		return;
	else {
		auto curIt = mapOfKey[key];
		auto preIt = curIt;
		if (curIt != buckets.begin())
			preIt--;

		if (curIt->val == 1) {
			mapOfKey.erase(key);
		}
		else if (curIt != buckets.begin() && preIt->val == curIt->val - 1) {
			preIt->keys.insert(key);
			mapOfKey[key] = preIt;
		}
		else {
			mapOfKey[key] = buckets.insert(curIt, { curIt->val - 1,{ key } });
		}

		curIt->keys.erase(key);
		if (curIt->keys.empty())
			buckets.erase(curIt);
	}
}

// Returns one of the keys with maximal value. 
string Solution::getMaxKey() {
	return buckets.empty() ? "" : *(buckets.rbegin()->keys.begin());
}

// Returns one of the keys with Minimal value. //
string Solution::getMinKey() {
	return buckets.empty() ? "" : *(buckets.begin()->keys.begin());
}

//348. Design Tic-Tac-Toe
int Solution::move(int row, int col, int player) {
	int inc = player == 1 ? 1 : -1;
	if (row == col)
		diagonal348 += inc;
	if (row == size348 - col - 1)
		anti_diagonal348 += inc;

	rows348[row] += inc;
	cols348[col] += inc;

	if (abs(rows348[row]) == size348 || abs(cols348[col]) == size348 || abs(diagonal348) == size348 || abs(anti_diagonal348) == size348)
		return player;

	return 0;
}
void Solution::TicTacToe(int n) {
	size348 = n;
	rows348.resize(size348, 0);
	cols348.resize(size348, 0);
	diagonal348 = 0;
	anti_diagonal348 = 0;
}

//186. Reverse Words in a String II
void Solution::reverseWords2(string &s) {
	int n = (int)s.size();
	reverse(s.begin(), s.end());
	for (int i = 0, j = 0; i <= n; i++)
		if (i == n || s[i] == ' ') {
			reverse(s.begin() + j, s.begin() + i);
			j = i + 1;
		}

	return;
}

//148. Sort List
Solution::ListNode* Solution::sortList(ListNode* head) {


	if (!head)return NULL;
	ListNode *dummy = new ListNode(0), *p, *q, *node = head;
	dummy->next = head;
	int unit = 1, countp, countq, len = 1;
	while (node = node->next)len++;
	while (unit<len) {
		q = p = dummy;
		while (p->next) {
			for (int i = 0; i<unit&&q->next; i++)q = q->next;
			if (!q->next)break;
			countp = countq = 0;
			while (countp<unit || countq<unit) {
				if (countp == unit) { countq++; q = q->next; }
				else if (countq<unit&&q->next->val<p->next->val) {
					node = q->next;
					q->next = node->next;
					node->next = p->next;
					p->next = node;
					countq++;
				}
				else countp++;
				p = p->next;
				if (!q->next)countq = unit;
			}
		}
		unit <<= 1;
	}
	return dummy->next;
}

Solution::ListNode* Solution::sortList_rec(ListNode* head) {
	if (!head || !head->next) return head;
	ListNode *l1, *l2, *n, **t, **m, **h = &head;
	unsigned int i, c = 1;
	while (1) {
		for (i = 0, m = h; i < c && *m; i++, m = &(*m)->next);
		if (i < c || !*m) {
			if (*h == head) return head;
			else { c *= 2; h = &head; continue; }
		}
		for (i = 0, t = m; i < c && *t; i++, t = &(*t)->next);
		n = *t, l1 = *h, l2 = *m;
		*m = *t = NULL;
		while (l1 && l2) {
			if (l1->val < l2->val) { *h = l1; l1 = l1->next; }
			else { *h = l2; l2 = l2->next; }
			h = &(*h)->next;
		}
		*h = l1 ? l1 : l2;
		while (*h) h = &(*h)->next;
		*h = n;
	}
}

//75. Sort Colors
void Solution::sortColors(vector<int>& nums) {
	sortColors(nums, 0, (int)nums.size() - 1);
}
void Solution::sortColors(vector<int>& nums, int left, int right) {
	if (left <= right)
		return;
	int i = left, j = right;
	int key = nums[i];
	while (i < j) {
		while (i < j && key <= nums[j])
			j--;
		nums[i] = nums[j];
		while (i < j && key >= nums[i])
			i++;
		nums[j] = nums[i];
	}
	nums[i] = key;

	sortColors(nums, left, i - 1);
	sortColors(nums, i + 1, right);
}

//200. Number of Islands
// Given a 2d grid map of '1's(land) and '0's(water), count the number of islands.An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.You may assume all four edges of the grid are all surrounded by water.
int Solution::numIslands(vector<vector<char>>& grid) {
	int count = 0;
	int n = grid.size();
	if (n == 0)
		return count;
	int m = grid[0].size();

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (grid[i][j] == '1') {
				dfsReset(grid, i, j);
				count++;
			}

	return count;
}

void Solution::dfsReset(vector<vector<char>>& grid, int i, int j) {
	if (i < 0 || j < 0 || i >= (int)grid.size() || j >= (int)grid[0].size() || grid[i][j] != '1')
		return;
	grid[i][j] = '0';
	dfsReset(grid, i - 1, j);
	dfsReset(grid, i + 1, j);
	dfsReset(grid, i, j - 1);
	dfsReset(grid, i, j + 1);
}

//218. The Skyline Problem
vector<pair<int, int>> Solution::getSkyline(vector<vector<int>>& buildings) {
	// use walls to record buildings; left wall is an insertion event, and right wall is a deletion event
	vector<pair<int, int>> walls, ans;                  // first: x, second: height
	for (auto b : buildings) {
		// push in left / right walls
		// let left wall has negative height to ensure left wall goes to multiset first if with same 'x' as right wall
		walls.push_back(make_pair(b[0], -b[2]));
		walls.push_back(make_pair(b[1], b[2]));
	}
	sort(walls.begin(), walls.end());                   // sort walls

	multiset<int> leftWallHeights = { 0 };                // keep left wall heights sorted; dummy '0' for convenience
	int top = 0;                                        // current max height among leftWallHeights
	for (auto w : walls) {
		if (w.second < 0) {                             // it's a left wall, insert the height
			leftWallHeights.insert(-w.second);
		}
		else {                                        // it's a right wall, delete the height
			leftWallHeights.erase(leftWallHeights.find(w.second));
		}

		if (*leftWallHeights.rbegin() != top) {         // mark a skyline point if top changes
			ans.push_back(make_pair(w.first, top = *leftWallHeights.rbegin()));
		}
	}

	return ans;
}

//297. Serialize and Deserialize Binary Tree
void Solution::serialize(TreeNode* root, ostringstream& out) {
	if (root) {
		out << root->val << ' ';
		serialize(root->left, out);
		serialize(root->right, out);
	}
	else
		out << "# ";
}
Solution::TreeNode* Solution::deserialize(istringstream& in) {
	string val;
	in >> val;
	if (val == "#")
		return nullptr;
	else {
		TreeNode* node = new TreeNode(stoi(val));
		node->left = deserialize(in);
		node->right = deserialize(in);
		return node;
	}
}
	// Encodes a tree to a single string.
	string Solution::serialize(TreeNode* root) {
		ostringstream out;
		stack<TreeNode*> nodes;
		while (!nodes.empty() || root != nullptr) {
			if (root != nullptr) {
				out << root->val << ' ';
				nodes.push(root);
				root = root->left;
			}
			else {
				out << "# ";
				root = nodes.top();
				nodes.pop();
				root = root->right;
			}
		}

		return out.str();
	}

	// Decodes your encoded data to tree.
	Solution::TreeNode* Solution::deserialize(string data) {
		istringstream in(data);
		return deserialize(in);
	}

	//268. Missing Number 
	int Solution::missingNumber(vector<int>& nums) {
		int sum = nums.size();

		for (int i = 0; i < (int)nums.size(); i++)
			sum += i - nums[i];

		return sum;
	}

	//116. Populating Next Right Pointers in Each Node 
	void Solution::connect(TreeLinkNode *root) {
		TreeLinkNode* levelStart = root;
		TreeLinkNode* cur = nullptr;
		while (levelStart) {
			cur = levelStart;
			while (cur) {
				if (cur->left)
					cur->left->next = cur->right;
				if (cur->right && cur->next)
					cur->right->next = cur->next->left;
				cur = cur->next;
			}
			levelStart = levelStart->left;
		}
	}

	//117. Populating Next Right Pointers in Each Node II Add to List
	void Solution::connect_I(TreeLinkNode *root) {
		TreeLinkNode* levelStart = root;
		TreeLinkNode* cur = nullptr;
		while (levelStart) {
			cur = levelStart;
			while (cur) {
				if (cur->left)
					cur->left->next = cur->right ? cur->right : nextChild(cur->next);
				if (cur->right)
					cur->right->next = nextChild(cur->next);
				cur = cur->next;
			}
			levelStart = nextChild(levelStart);
		}
	}

	Solution::TreeLinkNode* Solution::nextChild(TreeLinkNode* cur) {
		while (cur) {
			if (cur->left)
				return cur->left;
			if (cur->right)
				return cur->right;
			cur = cur->next;
		}
		return nullptr;
	}


	//73. Set Matrix Zeroes
	void Solution::setZeroes(vector<vector<int>>& matrix) {
		bool col0 = false;
		int rows = matrix.size();
		if (rows == 0)
			return;
		int cols = matrix[0].size();

		for (int i = 0; i < rows; i++) {
			if (matrix[i][0] == 0)
				col0 = true;
			for (int j = 1; j < cols; j++)
				if (matrix[i][j] == 0)
					matrix[i][0] = matrix[0][j] = 0;
		}

		for (int i = rows - 1; i >= 0; i--) {
			for (int j = cols - 1; j >= 1; j--)
				if (matrix[i][0] == 0 || matrix[0][j] == 0)
					matrix[i][j] = 0;
			if (col0)
				matrix[i][0] = 0;
		}
	}

	//98. Validate Binary Search Tree 
	bool Solution::isValidBST(TreeNode* root) {
		double pre = numeric_limits<double>::lowest();
		vector<int> ans;
		stack<TreeNode*> nodes;
		while (nodes.empty() == false || root != nullptr) {
			if (root != nullptr) {
				nodes.push(root);
				root = root->left;
			}
			else {
				root = nodes.top();
				nodes.pop();
				if (pre >= root->val)
				    return false;
				pre = root->val;
				ans.push_back(root->val);
				root = root->right;
			}
		}

		return true;
	}

	////208. Implement Trie (Prefix Tree) Pointer to Pointer Test
	void Solution::PointertoPointerTest() {
		TreeNode** ptrPtr1 = new TreeNode*[10];
		ptrPtr1[0] = new TreeNode(10);
		TreeNode* ptrPtr2[10] = { nullptr };
		ptrPtr2[0] = new TreeNode(20);

	}

	// 23. Merge k Sorted Lists
	void Solution::mergeKLists() {
		vector<ListNode*> lists;
		ListNode* p = new ListNode(0);
		p->next = new ListNode(2);
		p->next->next = new ListNode(5);
		lists.push_back(p);
		mergeKLists(lists);
	}
	Solution::ListNode* Solution::mergeKLists(vector<ListNode*>& lists) {
		ListNode helper(0);
		ListNode* p = &helper;

		for (int i = 0; i < (int)lists.size(); i++) {
			while (lists[i] != nullptr) {
				p->next = lists[i];
				p = p->next;
				lists[i] = lists[i]->next;
			}
		}
		return partitionSort(helper.next);
	}
	Solution::ListNode* Solution::partitionSort(ListNode* root) {
		if (root == nullptr || root->next == nullptr)
			return root;
		ListNode *slow = root, *fast = root;
		while (fast->next != nullptr && fast->next->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
		}
		fast = slow;
		slow = slow->next;
		fast->next = nullptr;

		ListNode* l1 = partitionSort(root);
		ListNode* l2 = partitionSort(slow);

		return mergeNodes(l1, l2);
	}
	Solution::ListNode* Solution::mergeNodes(ListNode* left, ListNode* right) {
		ListNode helper(0);
		ListNode *p = &helper;

		while (left&&right) {
			if (left->val <= right->val) {
				p->next = left;
				left = left->next;
			}
			else {
				p->next = right;
				right = right->next;
			}
			p = p->next;
		}
		p->next = left ? left : right;

		return helper.next;
	}

	//272. Closest Binary Search Tree Value II
	vector<int> Solution::closestKValues(TreeNode* root, double target, int k) {
		list<int> result;
		if (k == 0)
			return vector<int>();
		stack<TreeNode*> nodes;
		while (!nodes.empty() || root != nullptr) {
			if (root != nullptr) {
				nodes.push(root);
				root = root->left;
			}
			else {
				root = nodes.top();
				nodes.pop();
				if (--k >= 0)
					result.push_back(root->val);
				else {
					if (abs(root->val - target) < abs(result.front() - target)) {
						result.pop_front();
						result.push_back(root->val);
					}
					else
						break;
				}
				root = root->right;
			}
		}

		return vector<int>(result.begin(), result.end());
	}

	//212. Word Search II 
	TrieNode* Solution::buildTrie(vector<string>& words) {
		TrieNode* root = new TrieNode();
		for (string w : words) {
			TrieNode* p = root;
			for (char c : w) {
				int i = c - 'a';
				if (p->children[i] == nullptr)
					p->children[i] = new TrieNode();

				p = p->children[i];
			}
			p->word = w;
		}

		return root;
	}

	vector<string> Solution::findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<string> ans;
		TrieNode* root = buildTrie(words);
		for (int i = 0; i < (int)board.size(); i++)
			for (int j = 0; j < (int)board[0].size(); j++) {
				TrieNode* p = root;
				dfs(board, i, j, p, ans);
			}
		return ans;
	}

	void Solution::dfs(vector<vector<char>>& board, int i, int j, TrieNode* p, vector<string>& ans) {
		char c = board[i][j];
		if (c == '#' || p->children[c - 'a'] == nullptr)
			return;
		p = p->children[c - 'a'];
		if (!(p->word.empty())) {
			ans.push_back(p->word);
			p->word = "";
		}

		board[i][j] = '#';
		if (i > 0)
			dfs(board, i - 1, j, p, ans);
		if (j > 0)
			dfs(board, i, j - 1, p, ans);
		if (j + 1 < (int)board[0].size())
			dfs(board, i, j + 1, p, ans);
		if (i + 1 < (int)board.size())
			dfs(board, i + 1, j, p, ans);
		board[i][j] = c;
	}

	//333. Largest BST Subtree
	int Solution::largestBSTSubtree(TreeNode* root) {
		return bstSubTree(root)->nodes;
	}
	Solution::treeInfo* Solution::bstSubTree(TreeNode* root) {
		treeInfo *l, *r;

		if (root == nullptr) {
			treeInfo* result = new treeInfo();
			return result;
		}
		l = bstSubTree(root->left);
		r = bstSubTree(root->right);

		if ((root->left == nullptr || l->max < root->val) && (root->right == nullptr || r->min > root->val) && l->isBST && r->isBST) {
			l->min = root->left == nullptr ? root->val : l->min;
			l->max = root->right == nullptr ? root->val : r->max;
			l->nodes += r->nodes + 1;
			return l;
		}
		else {
			l->isBST = false;
			l->nodes = max(l->nodes, r->nodes);
			return l;
		}
	}

void Solution::morrisIn(TreeNode* head) {
		if (head == nullptr) {
			return;
		}
		TreeNode* cur1 = head;
		TreeNode* cur2 = nullptr;
		while (cur1 != nullptr) {
			cur2 = cur1->left;
			if (cur2 != nullptr) {
				while (cur2->right != nullptr && cur2->right != cur1) {
					cur2 = cur2->right;
				}
				if (cur2->right == nullptr) {
					cur2->right = cur1;
					cur1 = cur1->left;
					continue;
				}
				else {
					cur2->right = nullptr;
				}
			}
//			Sysetem.out.print(cur1->value + " ");
			cur1 = cur1->right;
		}
//		System.out.println();
	}

void Solution::morrisPre(TreeNode* head) {
    vector<int> ans;
	TreeNode *cur1 = head, *cur2 = nullptr;

	while (cur1 != nullptr) {
		cur2 = cur1->left;
		if (cur2 != nullptr) {
			while (cur2->right != nullptr && cur2->right != cur1)
				cur2 = cur2->right;
			if (cur2->right == nullptr) {
				cur2->right = cur1;
				ans.push_back(cur1->val);
				cur1 = cur1->left;
				continue;
			}
			if (cur2->right == cur1)
				cur2->right = nullptr;
		}
		else
			ans.push_back(cur1->val);
		cur1 = cur1->right;
	}
}

//451. Sort Characters By Frequency
string Solution::frequencySort(string s) {
	vector<int> count(256, 0);

	for (auto c : s)
		count[c]++;

	auto cmp = [&](char a, char b) { return (count[a] > count[b]) || (count[a] == count[b] && a < b); };
	sort(s.begin(), s.end(), cmp);

	return s;

/*
	vector<pair<int,int>> f(256, pair<int,int>(0,0));
	string ans = "";

	for (auto c : s) {
		f[(int)c].first++;
		f[(int)c].second = (int)c;
	}
	sort(f.begin(), f.end(), [&](pair<int, int> a, pair<int, int> b) { return a.first > b.first; });

	for (int i = (int)(f.size() - 1); i >= 0; i--) {
		int count = f[i].first;
		if (count != 0)
			while (count--)
				ans += (char)f[i].second;
	}

	return ans;
*/
	/*
	unordered_map<char, int> unorderedMap;
	multimap<int, char> hashMap;
	string ans = "";

	for (auto c : s)
		if ((unorderedMap.insert(pair<char, int>(c, 0))).second == false)
			unorderedMap[c]++;
	for (auto m : unorderedMap)
		hashMap.insert(pair<int, char>(m.second, m.first));
	for (auto it = hashMap.rbegin(); it != hashMap.rend(); it++) {
		int count = it->first;
		while (count--)
			ans += it->second;
	}
	return ans;
*/
}

//316. Remove Duplicate Letters
string Solution::removeDuplicateLetters(string s) {
	istringstream istr("AB.CD.ED.G");

	vector<unsigned int> cnt(26, 0); //only consider lowercase letters
	vector<bool> inRes(26, false); //true if the letter has been added to res 
	for (char ch : s) cnt[ch - 'a']++;
	string res = ""; //use res as a stack
	for (char ch : s) {
		cnt[ch - 'a']--;
		if (inRes[ch - 'a']) continue;
		while (!res.empty() && ch<res.back() && cnt[res.back() - 'a']>0) {
			inRes[res.back() - 'a'] = false;
			res.pop_back();

		}
		res.push_back(ch);
		inRes[ch - 'a'] = true;
	}
	return res;
}

//71. Simplify Path
string Solution::simplifyPath(string path) {
	istringstream is(path);
	deque<string> q;
	string str = "";
	while (getline(is, str, '/')) {
		if (str == "" || str == ".")
			continue;
		else if (str == "..") {
			if (!q.empty())
				q.pop_back();
		}
		else
			q.push_back(str);
	}
	str = "";
	while (!q.empty()) {
		str += "/" + q.front();
		q.pop_front();
	}
	return str.empty() ? "/" : str;

/*
	istringstream istr(path);

	string str = "";
	vector<string> tmpVec;
	while (getline(istr, str, '/')) {
		if (str == "" || str == ".")
			continue;
		else if (str == "..") {
			if (!tmpVec.empty())
				tmpVec.pop_back();
		}
		else
			tmpVec.push_back(str);
	}
	str = "";
	for (auto it = tmpVec.begin(); it != tmpVec.end(); it++)
		str += "/" + *it;

	return str.empty() ? "/" : str;
*/
}

//165. Compare Version Numbers
int Solution::compareVersion(string version1, string version2) {
	int n1 = version1.size(), n2 = version2.size();
	for (int i = 0, j = 0; i < n1 || j < n2; i++, j++) {
		int num1 = 0, num2 = 0;
		while (i < n1 && version1[i] != '.')
			num1 = num1 * 10 + (version1[i++] - '0');
		while (j < n2 && version2[j] != '.')
			num2 = num2 * 10 + (version2[j++] - '0');

		if (num1 > num2)
			return 1;
		else if (num1 < num2)
			return -1;
	}

	return 0;
}

void Solution::extraction(string s, vector<int>& v) {
	string tmpStr = "";
	for (auto c : s) {
		if (c != '.')
			tmpStr.push_back(c);
		else {
			if (tmpStr.empty() == false)
				v.push_back(stoi(tmpStr));
			tmpStr = "";
		}

	}

	if (tmpStr == s && s.empty() == false)
		v.push_back(stoi(s));

}

//91. Decode Ways
//Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12). 
int Solution::numDecodings(string s) {
	int n = s.size();
	if (n == 0)
		return 0;

	vector<int> dp(n + 1, 0);
	dp[n] = 1;
	dp[n - 1] = s[n - 1] == '0' ? 0 : 1;

	for (int i = n - 2; i >= 0; i--) {
		if (s[i] == '0')
			continue;
		dp[i] = stoi(s.substr(i, 2)) > 26 ? dp[i + 1] : dp[i + 1] + dp[i + 2];
	}

	return dp[0];
}

//125. Valid Palindrome
bool Solution::isPalindrome(string s) {

	for (int left = 0, right = s.size() - 1; left < right; left++, right--) {
		while (left < right && isalnum(s[left]) == false)
			left++;
		while (left < right && isalnum(s[right]) == false)
			right--;
		if (tolower(s[left]) != tolower(s[right]))
			return false;
	}

	return true;
	}

	bool Solution::invalid(char c) {
		if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z'))
			return false;
		else
			return true;
	}

	//25. Reverse Nodes in k-Group
	/*
	-1 -> 1 -> 2 -> 3 -> 4 -> 5
	|    |    |
	pre  cur  nex

	-1 -> 2 -> 1 -> 3 -> 4 -> 5
	|         |    |
	pre       cur  nex

	-1 -> 3 -> 2 -> 1 -> 4 -> 5
	|              |    |
	pre            cur  nex
	*/
	Solution::ListNode* Solution::reverseKGroup(ListNode* head, int k) {
		if (head == NULL || k == 1) return head;
		int num = 0;
		ListNode dummy(-1), *cur = &dummy, *nex = nullptr, *pre = &dummy;
		cur->next = head;
		while (cur = cur->next)
			num++;
		while (num >= k) {
			cur = pre->next;
			nex = cur->next;
			for (int i = 1; i<k; i++) {
				cur->next = nex->next;
				nex->next = pre->next;
				pre->next = nex;
				nex = cur->next;
			}
			pre = cur;
			num -= k;
		}
		return dummy.next;
	}


	Solution::ListNode* Solution::reverseLN(ListNode* head, int k) {
		ListNode *pre = nullptr, *ans = head;
		while (k-- > 0) {
			ListNode* tmp = head->next;
			head->next = pre;
			pre = head;
			head = tmp;
		}
		return ans;
	}
	void Solution::test25() {
		ListNode n1(1);
		ListNode n2(2);
		ListNode n3(3);
		ListNode n4(4);
		n1.next = &n2;
		n2.next = &n3;
		n3.next = &n4;
		reverseKGroup(&n1, 2);
	}

	//56. Merge Intervals
void Solution::test56() {
	Interval i1(1, 4);
	Interval i2(0, 4);
	vector<Interval> test56 = { i1, i2 };
	merge(test56);

	}
vector<Solution::Interval> Solution::merge(vector<Interval>& intervals) {
	vector<Interval> ans;
	if (intervals.empty())
		return vector<Interval>();

	sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) { return a.start < b.start; });
	ans.push_back(intervals[0]);

	for (int i = 1; i < (int)intervals.size(); i++) {
		if (ans.back().end < intervals[i].start)
			ans.push_back(intervals[i]);
		else
			ans.back().end = max(ans.back().end, intervals[i].end);
	}

	return ans;

	}

//interview 2016/11/18


//249. Group Shifted Strings
vector<vector<string>> Solution::groupStrings(vector<string>& strings) {
	unordered_map<string, vector<string> > mp;
	for (string s : strings)
		mp[shift(s)].push_back(s);
	vector<vector<string> > groups;
	for (auto m : mp)
		groups.push_back(m.second);

	return groups;
}

string Solution::shift(string& s) {
	string t = "";
	int n = s.length();
	if (n == 0)
		return "A";
	for (int i = 1; i < n; i++) {
		int diff = s[i] - s[i - 1];
		if (diff < 0) diff += 26;
		t += 'a' + diff;
	}
	return t;
	}

//78. Subsets
//  Initially: [[]]
//	Adding the first number to all the existed subsets : [[], [1]];
//  Adding the second number to all the existed subsets : [[], [1], [2], [1, 2]];
//  Adding the third number to all the existed subsets : [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]].
vector<vector<int>> Solution::subsets(vector<int>& nums) {
	vector<vector<int>> ans(1, vector<int>());

	

	for (int i = 0; i < (int)nums.size(); i++) {
		int n = ans.size();
		for (int j = 0; j < n; j++) {
			ans.push_back(ans[j]);
			ans.back().push_back(nums[i]);
		}
	}

	return ans;
}

//337. House Robber III
int Solution::robIII(TreeNode* root) {
	vector<int> ans = robSub(root);
	return max(ans[0], ans[1]);
}

	// ans[0] -> root is not robbed, ans[1] -> root is robbed
	vector<int> Solution::robSub(TreeNode* root) {
		vector<int> ans(2, 0), left(2, 0), right(2, 0);
		if (root == nullptr)
			return ans;

		left = robSub(root->left);
		right = robSub(root->right);

		ans[0] = max(left[0], left[1]) + max(right[0], right[1]);
		ans[1] = root->val + left[0] + right[0];

		return ans;
	}

	////273 Integer to English Words
	//1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
	string Solution::int2string(int n) {
		if (n >= 1000000000) {
			return int2string(n / 1000000000) + " Billion" + int2string(n % 1000000000);
		}
		else if (n >= 1000000) {
			return int2string(n / 1000000) + " Million" + int2string(n % 1000000);
		}
		else if (n >= 1000) {
			return int2string(n / 1000) + " Thousand" + int2string(n % 1000);
		}
		else if (n >= 100) {
			return int2string(n / 100) + " Hundred" + int2string(n % 100);
		}
		else if (n >= 20) {
			return  " " + tens[n / 10] + int2string(n % 10);
		}
		else if (n >= 1) {
			return " " + digits[n];
		}
		else {
			return "";
		}
	}

	string Solution::numberToWords(int num) {
		if (num == 0) {
			return "Zero";
		}
		else {
			string ret = int2string(num);
			return ret.substr(1, ret.length() - 1);
		}
	}
	//Quick sort
	void Solution::QuickSort(vector<int>& nums) {
		QuickSort(nums, 0, nums.size() - 1);
	}
	void Solution::QuickSort(vector<int>& nums, int left, int right) {
		if (left >= right)
			return;
		int pivot = nums[left + (right - left) / 2];
		int i = left, j = right;
		while (i <= j) {
			while (nums[j] > pivot)
				j--;
			while (nums[i] < pivot)
				i++;
			if (i <= j) {
				swap(nums[i], nums[j]);
				i++;
				j--;
			}
		}

		QuickSort(nums, left, j);
		QuickSort(nums, i, right);
	}

	//Merge Sort
	void Solution::MergeSort(vector<int>& nums) {
		if (nums.empty())
			return;
		MergeSort(nums, 0, nums.size() - 1);
	}

	void Solution::MergeSort(vector<int>& nums, int left, int right) {
		if (left < right) {
			int mid = 0;
			mid = left + (right - left) / 2;
			MergeSort(nums, left, mid);
			MergeSort(nums, mid + 1, right);
			MergeArray(nums, left, right, mid);
		}
	}

	void Solution::MergeArray(vector<int>& nums, int left, int right, int mid) {
		if (left >= right)
			return;

		vector<int> v(right - left + 1, 0);
		int i = left, k = 0, j = mid + 1;
		while (i <= mid && j <= right) {
			if (nums[i] < nums[j])
				v[k++] = nums[i++];
			else
				v[k++] = nums[j++];
		}
		while (i <= mid)
			v[k++] = nums[i++];
		while (j <= right)
			v[k++] = nums[j++];
		for (i = left, j = 0; i <= right; i++,j++)
			nums[i] = v[j];
	}

	//Heap sort
	//array是待调整的堆数组，i是待调整的数组元素的位置，nlength是数组的长度
	//本函数功能是：根据数组array构建大根堆
	void Solution::HeapAdjust(int array[], int i, int nLength)
	{
		int nChild;
		for (; 2 * i + 1 < nLength; i = nChild)
		{
			//子结点的位置=2*（父结点位置）+1
			nChild = 2 * i + 1;
			//得到子结点中较大的结点
			if (nChild < nLength - 1 && array[nChild + 1] > array[nChild])
				++nChild;
			//如果较大的子结点大于父结点那么把较大的子结点往上移动，替换它的父结点
			if (array[i] < array[nChild])
				swap(array[i], array[nChild]);
			else 
				break; 
			//否则退出循环
		}
	}
	//堆排序算法
	void Solution::HeapSort(int array[], int length)
	{
		int i;
		//调整序列的前半部分元素，调整完之后第一个元素是序列的最大的元素
		//length/2-1是最后一个非叶节点，此处"/"为整除
		for (i = length / 2 - 1; i >= 0; --i)
			HeapAdjust(array, i, length);
		//从最后一个元素开始对序列进行调整，不断的缩小调整的范围直到第一个元素
		for (i = length - 1; i>0; --i)
		{
			//把第一个元素和当前的最后一个元素交换，
			//保证当前的最后一个位置的元素都是在现在的这个序列之中最大的
			swap(array[i], array[0]);
			//不断缩小调整heap的范围，每一次调整完毕保证第一个元素是当前序列的最大值
			HeapAdjust(array, 0, i);
		}
	}

	//54 Spiral Matrix
	vector<int> Solution::spiralOrder(vector<vector<int>>& matrix) {
		vector<vector<int> > dirs{ { 0, 1 },{ 1, 0 },{ 0, -1 },{ -1, 0 } };
		vector<int> res;
		int nr = matrix.size();     if (nr == 0) return res;
		int nc = matrix[0].size();  if (nc == 0) return res;

		vector<int> nSteps{ nc, nr - 1 };

		int iDir = 0;   // index of direction.
		int ir = 0, ic = -1;    // initial position
		while (nSteps[iDir % 2]) {
			for (int i = 0; i < nSteps[iDir % 2]; ++i) {
				ir += dirs[iDir][0]; ic += dirs[iDir][1];
				res.push_back(matrix[ir][ic]);
			}
			nSteps[iDir % 2]--;
			iDir = (iDir + 1) % 4;
		}
		return res;

	}

	//236. Lowest Common Ancestor of a Binary Tree
	Solution::TreeNode* Solution::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		Frame answer;
		stack<Frame> stack;
		stack.push({ root, &answer });
		while (stack.size()) {
			Frame *top = &stack.top(), *parent = top->parent;
			TreeNode *node = top->node;
			if (!node || node == p || node == q) {
				parent->subs.push_back(node);
				stack.pop();
			}
			else if (top->subs.empty()) {
				stack.push({ node->right, top });
				stack.push({ node->left, top });
			}
			else {
				TreeNode *left = top->subs[0], *right = top->subs[1];
				parent->subs.push_back(!left ? right : !right ? left : node);
				stack.pop();
			}
		}
		return answer.subs[0];
/*
		if (!root || root == p || root == q) return root;
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		return !left ? right : !right ? left : root;
*/
	}

	//48. Rotate Image
	void Solution::rotate(vector<vector<int>>& matrix) {
		int b = (int)matrix.size() - 1;
		int a = 0;
		while (a<b) {
			for (int i = 0; i<(b - a); ++i) {
				swap(matrix[a][a + i], matrix[a + i][b]);
				swap(matrix[a][a + i], matrix[b][b - i]);
				swap(matrix[a][a + i], matrix[b - i][a]);
			}
			++a;
			--b;
		}
	}
    
	//103. Binary Tree Zigzag Level Order Traversal
	vector<vector<int>> Solution::zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		zigzagLevelOrder(root, 0, ans);

		for (int i = 0; i < (int)ans.size(); i++)
			if (i % 2)
				reverse(ans[i].begin(), ans[i].end());

		return ans;
	}
	void Solution::zigzagLevelOrder(TreeNode* root, int depth, vector<vector<int>>& v) {
		if (root == nullptr)
			return;

		if (v.size() == depth)
			v.push_back(vector<int>());

		v[depth].push_back(root->val);
		zigzagLevelOrder(root->left, depth + 1, v);
		zigzagLevelOrder(root->right, depth + 1, v);

		return;
	}

	// 53. Maximum Subarray
	int Solution::maxSubArray(vector<int>& nums) {
		int n = nums.size();

		int max = nums[0];
		int i = 0;
		for (; i < n; i++) {
			if (nums[i] > max)
				max = nums[i];
			if (nums[i] > 0)
				break;
		}

		int sum = 0;
		for (; i < n; i++) {
			sum += nums[i];
			if (sum > max)
				max = sum;
			if (sum < 0)
				sum = 0;
		}

		return max;
	}

	//174. Dungeon Game
	int Solution::calculateMinimumHP(vector<vector<int>>& dungeon) {
		int rows = dungeon.size();
		if (rows == 0)
			return 1;
		int cols = dungeon[0].size();
		if (cols == 0)
			return 1;

		dungeon[rows - 1][cols - 1] = max(1, 1 - dungeon[rows - 1][cols - 1]);

		for (int i = rows - 2; i >= 0; i--)
			dungeon[i][cols - 1] = max(1, dungeon[i + 1][cols - 1] - dungeon[i][cols - 1]);
		for (int j = cols - 2; j >= 0; j--)
			dungeon[rows - 1][j] = max(1, dungeon[rows - 1][j + 1] - dungeon[rows - 1][j]);

		for (int i = rows - 2; i >= 0; i--)
			for (int j = cols - 2; j >= 0; j--)
				dungeon[i][j] = max(1, min(dungeon[i + 1][j], dungeon[i][j + 1]) - dungeon[i][j]);

		return dungeon[0][0];
		/*
		int n=dungeon.size(),m=dungeon[0].size();
		vector<int> dp(n+1,INT_MAX);
		dp[n-1]=1;
		for(int j=m-1;j>=0;j--){
		for(int i=n-1;i>=0;i--){
		dp[i]=min(dp[i],dp[i+1])-dungeon[i][j];
		dp[i]=max(1,dp[i]);
		}
		}
		return dp[0];
		*/
	}

	//33. Search in Rotated Sorted Array
	int Solution::search(vector<int>& nums, int target) {
		int n = nums.size(), lo = 0, hi = n - 1;
		// find the index of the smallest value using binary search.
		// Loop will terminate since mid < hi, and lo or hi will shrink by at least 1.
		// Proof by contradiction that mid < hi: if mid==hi, then lo==hi and loop would have been terminated.
		while (lo<hi) {
			int mid = lo + (hi - lo) / 2;
			if (nums[mid]>nums[hi]) lo = mid + 1;
			else hi = mid;
		}
		// lo==hi is the index of the smallest value and also the number of places rotated.
		int rot = lo;
		lo = 0; hi = n - 1;
		// The usual binary search and accounting for rotation.
		while (lo <= hi) {
			int mid = lo + (hi - lo) / 2;
			int realmid = (mid + rot) % n;
			if (nums[realmid] == target)return realmid;
			if (nums[realmid]<target)lo = mid + 1;
			else hi = mid - 1;
		}
		return -1;
	}

	//153. Find Minimum in Rotated Sorted Array
	int Solution::findMin(vector<int>& nums) {
		int n = nums.size(), lo = 0, hi = n - 1;
		// find the index of the smallest value using binary search.
		// Loop will terminate since mid < hi, and lo or hi will shrink by at least 1.
		// Proof by contradiction that mid < hi: if mid==hi, then lo==hi and loop would have been terminated.
		while (lo<hi) {
			int mid = (lo + hi) / 2;
			if (nums[mid]>nums[hi]) lo = mid + 1;
			else hi = mid;
		}
		return nums[lo];
	}

	//24. Swap Nodes in Pairs
	Solution::ListNode* Solution::swapPairs(ListNode* head) {
		ListNode dummy(0), *cur = &dummy;
		cur->next = head;
		while (cur->next != nullptr && cur->next->next != nullptr) {
			ListNode* first = cur->next;
			ListNode* second = cur->next->next;
			cur->next = second;
			first->next = second->next;
			second->next = first;
			cur = cur->next->next;
		}
		return dummy.next;
	}

	//215. Kth Largest Element in an Array Add to List
	int Solution::partition215(vector<int>& nums, int left, int right) {
		int pivot = nums[left];
		while (left < right) {
			while (left < right && nums[right] >= pivot)
				right--;
			nums[left] = nums[right];
			while (left < right && nums[left] <= pivot)
				left++;
			nums[right] = nums[left];
		}
		nums[left] = pivot;
		return left;
	}

	int Solution::findKthLargest(vector<int>& nums, int k) {
		int n = nums.size();
		int left = 0, right = n - 1;
		while (true) {
			int pos = partition215(nums, left, right);
			if (pos == n - k) return nums[pos];
			if (pos > n - k) right = pos - 1;
			else left = pos + 1;
		}
	}

	//191. Number of 1 Bits
	int Solution::hammingWeight(uint32_t n) {
		bitset<128> test(n);
		test[0] = 1;
		test[31] = 1;
		return test.count();
		//        return bitset<32>(n).count();
	}

	//23. Merge k Sorted Lists

	Solution::ListNode* Solution::mergeKLists23(vector<ListNode*>& lists) {
		priority_queue<ListNode*, vector<ListNode*>, myComp23> heap;
		ListNode dummy(0), *cur = &dummy;
		int n = lists.size();
		for (int i = 0; i < n; i++)
			if (lists[i])
				heap.push(lists[i]);
		while (heap.empty() == false) {
			cur->next = heap.top();
			heap.pop();
			cur = cur->next;
			if (cur->next)
				heap.push(cur->next);
		}

		return dummy.next;
	}

	//46. Permutations Add to List
	vector<vector<int> > Solution::permute(vector<int> &num) {
		vector<vector<int> > result;

		permuteRecursive(num, 0, result);
		return result;
	}

	// permute num[begin..end]
	// invariant: num[0..begin-1] have been fixed/permuted
	void Solution::permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result) {
		if (begin >= (int)num.size()) {
			// one permutation instance
			result.push_back(num);
			return;
		}

		for (int i = begin; i < (int)num.size(); i++) {
			swap(num[begin], num[i]);
			permuteRecursive(num, begin + 1, result);
			// reset
			swap(num[begin], num[i]);
		}
	}

	//47. Permutations II Add to List
	vector<vector<int>> Solution::permuteUnique(vector<int>& nums) {
		vector<vector<int> > result;

		permuteUnique(nums, 0, result);
		return result;
	}

	// permute num[begin..end]
	// invariant: num[0..begin-1] have been fixed/permuted
	void Solution::permuteUnique(vector<int> &num, int begin, vector<vector<int> > &result) {
		if (begin >= (int)num.size()) {
			// one permutation instance
			result.push_back(num);
			return;
		}

		unordered_map<int, int> hash;
		for (int i = begin; i < (int)num.size(); i++) {
			if (hash[num[i]]++ > 0)
				continue;

			swap(num[begin], num[i]);
			permuteUnique(num, begin + 1, result);
			// reset
			swap(num[begin], num[i]);
		}
	}

	//112. Path Sum
	bool Solution::hasPathSum(TreeNode* root, int sum) {
		if (nullptr == root)
			return false;

		if (root->val == sum && root->left == nullptr && root->right == nullptr)
			return true;

		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	}

	//124. Binary Tree Maximum Path Sum 
	int Solution::maxPathSum(TreeNode* root) {
		if (root == nullptr)
			return 0;
		int maxSum = root->val;
		maxPathSum(root, maxSum);
		return maxSum;
	}

	int Solution::maxPathSum(TreeNode* root, int &maxSum) {
		if (root == nullptr)
			return 0;
		int left = max(0, maxPathSum(root->left, maxSum));
		int right = max(0, maxPathSum(root->right, maxSum));
		maxSum = max(maxSum, left + right + root->val);
		return max(left, right) + root->val;
	}

	//114. Flatten Binary Tree to Linked List
	void Solution::flatten(TreeNode* root) {
		//morris algorithm
		TreeNode *now = root;
		while (now)
		{
			if (now->left)
			{
				//Find current node's prenode that links to current node's right subtree
				TreeNode* pre = now->left;
				while (pre->right)
				{
					pre = pre->right;
				}
				pre->right = now->right;
				//Use current node's left subtree to replace its right subtree(original right 
				//subtree is already linked by current node's prenode
				now->right = now->left;
				now->left = NULL;
			}
			now = now->right;
		}
	}

	//55. Jump Game 
	bool Solution::canJump(vector<int>& nums) {
		int n = nums.size();
		if (n == 0)
			return true;

		int range = nums[0];
		for (int i = 0; i <= range; i++) {
			range = max(range, i + nums[i]);
			if (range >= n - 1)
				return true;
		}

		return false;
	}

	//92. Reverse Linked List II
	void Solution::test92() {
		ListNode dummy(0);
		dummy.next = new ListNode(1);
		reverseBetween(&dummy, 1, 2);
	}
	Solution::ListNode* Solution::reverseBetween(ListNode* head, int m, int n) {
		ListNode dummy(0), *cur = &dummy;
		cur->next = head;
		int k = n - m;
		while (--m)
			cur = cur->next;
		ListNode* next1 = cur->next;
		ListNode* next2 = next1->next;
		while (k--) {
			next1->next = next2->next;
			next2->next = cur->next;
			cur->next = next2;
			next2 = next1->next;
		}

		return dummy.next;
	}

	// Check wether a binary tree is a full binary tree
	bool Solution::isFullBinaryTree(TreeNode* root) {
		if (root == nullptr)
			return true;
		queue<TreeNode*> nodes;
		TreeNode* front = nullptr;
		nodes.push(root);
		while (front = nodes.front()) {
			nodes.push(front->left);
			nodes.push(front->right);
			nodes.pop();
		}
		while (nodes.empty() != true) {
			if (nodes.front() != nullptr)
				return false;
			nodes.pop();
		}

		return true;
}

	//change a binary tree to double linked list
	Solution::TreeNode* Solution::changeBinaryTreeToDoubleLinkedList(TreeNode* root) {
		TreeNode dummy(0), *pre = &dummy;
		stack<TreeNode*> nodes;
		while (nodes.empty() != true || root != nullptr) {
			if (root != nullptr) {
				nodes.push(root);
				root = root->left;
			}
			else {
				root = nodes.top();
				nodes.pop();
				pre->right = root;
				root->left = pre;
				pre = root;
				root = root->right;
			}
		}
		if (dummy.right != nullptr)
			dummy.right->left = nullptr;
		return dummy.right;
	}

	//448. Find All Numbers Disappeared in an Array
	vector<int> Solution::findDisappearedNumbers(vector<int>& nums) {
		vector<int> ans;

		for (auto num : nums) {
			int index = abs(num) - 1;
			if (nums[index] > 0)
				nums[index] = -nums[index];
		}

		for (int i = 0; i < (int)nums.size(); i++) {
			if (nums[i] > 0)
				ans.push_back(i + 1);
		}

		return ans;
	}

	//338. Counting Bits
	vector<int> Solution::countBits(int num) {
		vector<int> ret(num + 1, 0);
		for (int i = 1; i <= num; ++i)
			ret[i] = ret[i&(i - 1)] + 1;
		return ret;
	}

	//401. Binary Watch Add to List
	vector<string> Solution::readBinaryWatch(int num) {
		vector<int> hour[4], minute[6];
		for (int i = 0; i < 12; i++) {
			int n = bitset<4>(i).count();
			hour[n].push_back(i);
		}
		for (int i = 0; i < 60; i++) {
			int n = bitset<6>(i).count();
			minute[n].push_back(i);
		}

		//
		vector<string> ans;
		for (int i = 0; i <= num && i < 4; i++)
			for (int h = 0; h < (int)hour[i].size(); h++)
				for (int m = 0; num - i < 6 && m < (int)minute[num - i].size(); m++) {
					string tmp = to_string(hour[i][h]) + ":";
					if (minute[num - i][m] < 10)
						tmp += "0";
					tmp += to_string(minute[num - i][m]);

					ans.push_back(tmp);
				}

		return ans;
	}

	/*
	Here is my solution to implement a Least Frequently Used Cache in C++.
	The idea is straightforward. We maintain a min-PriorityQueue with the least frequently used element at the top. However, when we access any existing element using get() or set(), its usage frequency should be increased by one, which forces us to change its position in the priority queue (re-heapify). Unfortunately, native STL PriorityQueue does not support this operation. Therefore, we need to create our own priority queue and modify it. I found the so-called Index Priority Queue is suitable for this task (believe me, it is very simple to grasp. Use it to impress your interviewer!). It maintains not only a priority queue but also a hash map, "indexMap", that maps the key of an element to its position (index) in the priority queue. Now, we can quickly access any element in the priority queue and re-heapify the PriorityQueue, when the usage frequency of an element changes.
	Another tricky point is that when we need to evict an element, but multiple elements have the same (minimum) usage frequency, we need to evict the least recently used (the oldest) element. To handle this, I maintain a time-stamp variable for each element in the LFU Cache, which indicates the latest time stamp when we access it. Therefore, we maintain the following invariant in the priority queue: When two elements have the same usage frequency, the least recently used one will always be closer to root node. When there are multiple least frequently used elements, we always retrieve the one closer to the root.
	*/
	/*
	class LFUCache {
	public:
	struct Node {
	int key; // key of the element.
	int val; // value of the ement.
	int fre; // usage frequency
	int timeStamp; // the latest time stamp when this element is accessed.
	Node(): key(-1), val(-1), timeStamp(-1), fre(0) {}
	Node(int k, int v, int ts): key(k), val(v), timeStamp(ts), fre(1) {}
	};

	LFUCache(int capacity) {
	Cap = capacity;
	Node* dummy = new Node();
	pq.push_back(dummy); // The pq start from pq[1].
	ts = 0;
	}

	int get(int key) {
	if(!mp.count(key)) return -1;
	int index = mp[key];
	int val = pq[index]->val;
	pq[index]->fre++;
	pq[index]->timeStamp = ++ts;
	sink(index);
	return val;
	}

	void set(int key, int value) {
	if(Cap <= 0) return;
	if(mp.count(key)) {
	int index = mp[key];
	pq[index]->val = value;
	get(key);
	}
	else {
	if(pq.size() - 1 == Cap) {
	int oldKey = pq[1]->key;
	mp.erase(oldKey);
	Node* newnode = new Node(key, value, ++ts);
	pq[1] = newnode;
	mp[key] = 1;
	sink(1);
	}
	else {
	Node* newnode = new Node(key, value, ++ts);
	pq.push_back(newnode);
	mp[key] = pq.size() - 1;
	swim(pq.size() - 1);
	}
	}
	}

	private:
	vector<Node*> pq; // A priority queue, with the least usage frequency and least recently used element at the top.
	unordered_map<int, int> mp; // A mapping from the key of the element to its index in the priority queue.
	int Cap; // Capcity of the cache
	int ts; // time-stamp: indicate the time stamp of the latest operation of an element. According to the requirement of LFU cache, when we need to evict an element from the cache, but there are multiple elements with the same minimum frequency, then the least recently used element should be evicted.

	/*
	* Recursively sink a node in priority queue. A node will be sinked, when its frequency is larger than any of its
	* children nodes, or the node has the same frequency with a child, but it is recently updated.

	void sink(int index) {
	int left = 2 * index, right = 2 * index + 1, target = index;
	if(left < pq.size() && pq[left]->fre <= pq[target]->fre) // If the left child has the same frequency, we probably need to swap the parent node and the child node, because the parent node is recently accessed, and the left child node was accessed at an older time stamp.
	target = left;
	if(right < pq.size()) {
	if(pq[right]->fre < pq[target]->fre || (pq[right]->fre == pq[target]->fre && pq[right]->timeStamp < pq[target]->timeStamp)) // If right child has the same frequency and an older time stamp, we must swap it.
	target = right;
	}
	if(target != index) {
	myswap(target, index);
	sink(target);
	}
	}

	/*a
	* Recursively swim a node in priority queue. A node will be swimmed, when its frequency is less than its
	* parent node. If the node has the same frequency with its parent, it is not needed to be swimmed, because
	* it is recently accessed.

	void swim(int index) {
	int par = index / 2;
	while(par > 0 && pq[par]->fre > pq[index]->fre) {
	myswap(par, index);
	index = par;
	par /= 2;
	}
	}

	void myswap(int id1, int id2) {
	swap(pq[id1], pq[id2]);
	mp[pq[id1]->key] = id1;
	mp[pq[id2]->key] = id2;
	}
	};
	*/
	/*
	class LFUCache {
	public:
	LFUCache(int capacity) {
	this->capacity = capacity;
	head = new dequeKeys(0);
	tail = new dequeKeys(0);
	head->next = tail;
	tail->pre = head;
	}

	int get(int key) {
	if(hashmap.find(key) == hashmap.end())
	return -1;
	else {
	increaseFreq(key);
	return hashmap[key].first;
	}
	}

	void set(int key, int value) {
	if(hashmap.find(key) != hashmap.end()) {
	hashmap[key].first = value;
	increaseFreq(key);
	}
	else {
	if(hashmap.size() == capacity) {
	if(capacity == 0)
	return;
	hashmap.erase(head->next->keys.front());
	head->next->keys.pop_front();
	if(head->next->keys.empty()) {
	dequeKeys *node = head->next;
	head->next = head->next->next;
	head->next->pre = head;
	delete node;
	}
	}
	if(head->next->freq == 1) {
	head->next->keys.push_back(key);
	}
	else {
	dequeKeys *node = new dequeKeys(1);
	node->next = head->next;
	head->next = node;
	node->next->pre = node;
	node->pre = head;
	node->keys.push_back(key);
	}
	hashmap[key] = pair<int, dequeKeys*>(value, head->next);
	}
	}

	void increaseFreq(int key) {
	dequeKeys *cur = hashmap[key].second;
	if(cur->next->freq == cur->freq + 1) {
	cur->next->keys.push_back(key);
	}
	else {
	dequeKeys *node = new dequeKeys(cur->freq + 1);
	node->next = cur->next;
	cur->next = node;
	node->next->pre = node;
	node->pre = cur;
	node->keys.push_back(key);
	}
	hashmap[key].second = cur->next;

	cur->keys.remove(key);
	if(cur->keys.empty()) {
	cur->pre->next = cur->next;
	cur->next->pre = cur->pre;
	delete cur;
	}
	}

	private:
	struct dequeKeys {
	int freq;
	list<int> keys;
	dequeKeys *pre;
	dequeKeys *next;
	dequeKeys(int a): freq(a), pre(nullptr), next(nullptr) {}
	};

	int capacity;
	dequeKeys *head = nullptr, *tail = nullptr;
	unordered_map<int, pair<int, dequeKeys*>> hashmap;
	};
	*/

	//460. LFU Cache Add to List
	void Solution::LFUCache(int capacity) {
		mycapacity = capacity;
/*
		this->capacity = capacity;
		head = new dequeKeys(0);
		tail = new dequeKeys(0);
		head->next = tail;
		tail->pre = head;
*/
	}

	int Solution::get_460(int key) {
		if (mycapacity == 0)
			return -1;
		auto it = hashmap_460.find(key);
		if (it == hashmap_460.end())
			return -1;
		auto p1 = it->second.second;
		auto p2 = p1;
		p2++;
		if (p2 != mylist_460.end() && p2->first == p1->first + 1)
			p2->second.push_back(key);
		else
			p2 = mylist_460.insert(p2, pair<int, list<int>>(p1->first + 1, list<int>{key}));

		p1->second.remove(key);
		if (p1->second.empty())
			mylist_460.erase(p1);

		it->second.second = p2;
		return it->second.first;
		/*
		if (hashmap.find(key) == hashmap.end())
			return -1;
		else {
			increaseFreq(key);
			return hashmap[key].first;
		}
*/
	}
	void Solution::set_460(int key, int value) {
		if (mycapacity == 0)
			return;
		if (get_460(key) != -1)
			hashmap_460[key].first = value;
		else {
			if (hashmap_460.size() == mycapacity) {
				hashmap_460.erase(mylist_460.front().second.front());
				mylist_460.front().second.pop_front();
				if (mylist_460.front().second.empty())
					mylist_460.pop_front();
			}
			if (mylist_460.empty() || mylist_460.front().first != 1)
				mylist_460.push_front(pair<int, list<int>>(1, list<int>{key}));
			else
				mylist_460.front().second.push_back(key);

			hashmap_460[key] = pair<int, list<pair<int, list<int>>>::iterator>(value, mylist_460.begin());
		}
		/*
		if (hashmap.find(key) != hashmap.end()) {
			hashmap[key].first = value;
			increaseFreq(key);
		}
		else {
			if (hashmap.size() == capacity) {
				if (capacity == 0)
					return;
				hashmap.erase(head->next->keys.front());
				head->next->keys.pop_front();
				if (head->next->keys.empty()) {
					dequeKeys *node = head->next;
					head->next = head->next->next;
					head->next->pre = head;
					delete node;
				}
			}
			if (head->next->freq == 1) {
				head->next->keys.push_back(key);
			}
			else {
				dequeKeys *node = new dequeKeys(1);
				node->next = head->next;
				head->next = node;
				node->next->pre = node;
				node->pre = head;
				node->keys.push_back(key);
			}
			hashmap[key] = pair<int, dequeKeys*>(value, head->next);
		}
*/
	}

	void Solution::increaseFreq(int key) {
		dequeKeys *cur = hashmap[key].second;
		if (cur->next->freq == cur->freq + 1) {
			cur->next->keys.push_back(key);
		}
		else {
			dequeKeys *node = new dequeKeys(cur->freq + 1);
			node->next = cur->next;
			cur->next = node;
			node->next->pre = node;
			node->pre = cur;
			node->keys.push_back(key);
		}
		hashmap[key].second = cur->next;

		cur->keys.remove(key);
		if (cur->keys.empty()) {
			cur->pre->next = cur->next;
			cur->next->pre = cur->pre;
			delete cur;
		}
	}

	//457. Circular Array Loop
	bool Solution::circularArrayLoop(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			if (nums[i] == 0) {
				continue;
			}

			// slow/fast pointer
			int j = i, k = getIndex(i, nums);
			// check if it's same direction
			while (nums[k] * nums[i] > 0 && nums[getIndex(k, nums)] * nums[i] > 0) {
				if (j == k) {
					// check for loop with only one element
					if (j == getIndex(j, nums)) {
						break;
					}
					return true;
				}
				j = getIndex(j, nums);
				k = getIndex(getIndex(k, nums), nums);
			}

			// loop not found, set all element along the way to 0
			j = i;
			int val = nums[i];
			while (nums[j] * val > 0) {
				int next = getIndex(j, nums);
				nums[j] = 0;
				j = next;
			}
		}
		return false;
	}

	int Solution::getIndex(int i, vector<int>& nums) {
		int n = nums.size();
		return i + nums[i] >= 0 ? (i + nums[i]) % n : n + ((i + nums[i]) % n);
	}

	//328. Odd Even Linked List 
	Solution::ListNode* Solution::oddEvenList(ListNode* head) {
		if (head != nullptr) {
			ListNode *odd = head, *even = head->next, *evenHead = even;
			while (even != nullptr && even->next != nullptr) {
				odd->next = odd->next->next;
				even->next = even->next->next;
				odd = odd->next;
				even = even->next;
			}
			odd->next = evenHead;
		}

		return head;
	}

	//139. Word Break Add to List
	bool Solution::wordBreak(string s, unordered_set<string>& wordDict) {
		if (wordDict.size() == 0)
			return false;
		int n = s.size();
		vector<bool> dp(n + 1, false);
		dp[0] = true;
		for (int i = 1; i <= n; i++) {
			for (int j = i - 1; j >= 0; j--) {
				if (dp[j]) {
					string w = s.substr(j, i - j);
					if (wordDict.find(w) != wordDict.end()) {
						dp[i] = true;
						break;
					}
				}
			}
		}

		return dp[n];
	}

	Solution::TreeNode* Solution::closestValue(TreeNode* root, TreeNode* p, TreeNode*& closest) {
		if (root == nullptr || p == nullptr)
			return nullptr;
		closest = root;
		if (abs(root->val - p->val) < abs(closest->val - p->val))
			closest = root;
		closestValue(root->left, p, closest);
		closestValue(root->right, p, closest);

		return closest;
	}

	//152. Maximum Product Subarray Add to List
	int Solution::maxProduct(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int tmpMax = nums[0], tmpMin = nums[0], ans = nums[0];

		for (int i = 1; i < (int)nums.size(); i++) {
			int m = tmpMax;
			tmpMax = max(max(tmpMax * nums[i], tmpMin * nums[i]), nums[i]);
			tmpMin = min(min(m * nums[i], tmpMin * nums[i]), nums[i]);
			ans = max(ans, tmpMax);
		}

		return ans;
	}

	/*96. Unique Binary Search Trees
	The problem can be solved in a dynamic programming way.
	Given a sequence 1…n, to construct a Binary Search Tree (BST) out of the sequence, we could enumerate each number i in the sequence, and use the number as the root, naturally, the subsequence 1…(i-1) on its left side would lay on the left branch of the root, and similarly the right subsequence (i+1)…n lay on the right branch of the root. We then can construct the subtree from the subsequence recursively. Through the above approach, we could ensure that the BST that we construct are all unique, since they have unique roots.
	The problem is to calculate the number of unique BST. To do so, we need to define two functions:
	G(n): the number of unique BST for a sequence of length n.
	F(i, n), 1 <= i <= n: the number of unique BST, where the number i is the root of BST, and the sequence ranges from 1 to n.
	As one can see, G(n) is the actual function we need to calculate in order to solve the problem. And G(n) can be derived from F(i, n), which at the end, would recursively refer to G(n).
	First of all, given the above definitions, we can see that the total number of unique BST G(n), is the sum of BST F(i) using each number i as a root.
	i.e.
	G(n) = F(1, n) + F(2, n) + ... + F(n, n).
	Particularly, the bottom cases, there is only one combination to construct a BST out of a sequence of length 1 (only a root) or 0 (empty tree).
	i.e.
	G(0)=1, G(1)=1.
	Given a sequence 1…n, we pick a number i out of the sequence as the root, then the number of unique BST with the specified root F(i), is the cartesian product of the number of BST for its left and right subtrees. For example, F(3, 7): the number of unique BST tree with number 3 as its root. To construct an unique BST out of the entire sequence [1, 2, 3, 4, 5, 6, 7] with 3 as the root, which is to say, we need to construct an unique BST out of its left subsequence [1, 2] and another BST out of the right subsequence [4, 5, 6, 7], and then combine them together (i.e. cartesian product). The tricky part is that we could consider the number of unique BST out of sequence [1,2] as G(2), and the number of of unique BST out of sequence [4, 5, 6, 7] as G(4). Therefore, F(3,7) = G(2) * G(4).
	i.e.
	F(i, n) = G(i-1) * G(n-i)	1 <= i <= n
	Combining the above two formulas, we obtain the recursive formula for G(n). i.e.
	G(n) = G(0) * G(n-1) + G(1) * G(n-2) + … + G(n-1) * G(0)
	In terms of calculation, we need to start with the lower number, since the value of G(n) depends on the values of G(0) … G(n-1).
	*/
	int Solution::numTrees(int n) {
		vector<int> ans(n + 1, 0);
		if (n <= 0) return 1;

		ans[0] = ans[1] = 1;
		for (int i = 2; i <= n; i++)
			for (int j = 1; j <= i; j++)
				ans[i] += ans[j - 1] * ans[i - j];

		return ans[n];
	}

	//419. Battleships in a Board
	int Solution::countBattleships(vector<vector<char>>& board) {
		if (board.size() == 0 || board[0].size() == 0)
			return 0;

		int ans = 0, row = board.size(), col = board[0].size();

		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
			{
				if (board[i][j] == 'X' && (i == 0 || board[i - 1][j] == '.') && (j == 0 || board[i][j - 1] == '.'))
					ans++;
			}

		return ans;
	}

	//140. Word Break II
	vector<string> Solution::wordBreak_140(string s, vector<string>& wordDict) {
		if (hashmap_140.find(s) != hashmap_140.end())
			return hashmap_140[s];
		vector<string> ans;
		if (std::find(wordDict.begin(), wordDict.end(), s) != wordDict.end())
			ans.push_back(s);

		for (int i = 1; i < (int)s.size(); i++) {
			string v = s.substr(i);
			if (std::find(wordDict.begin(), wordDict.end(), v) != wordDict.end()) {
				string w = s.substr(0, i);
				vector<string> pre = combine(v, wordBreak_140(w, wordDict));
				ans.insert(ans.end(), pre.begin(), pre.end());
			}
		}
		hashmap_140[s] = ans;

		return ans;
	}

	vector<string> Solution::combine(string s, vector<string> pre) {
		for (int i = 0; i < (int)pre.size(); i++) {
			pre[i] += " " + s;
		}

		return pre;
	}

	//11. Container With Most Water Add to List 
	int Solution::maxArea(vector<int>& height) {
		int water = 0, i = 0, j = height.size() - 1;

		while (i < j) {
			int h = min(height[i], height[j]);
			water = max(water, h * (j - i));

			while (i < j && height[i] <= h)
				i++;
			while (i < j && height[j] <= h)
				j--;
		}

		return water;
	}

	//188. Best Time to Buy and Sell Stock IV 
	int Solution::maxProfit_IV(int k, vector<int>& prices) {

		int len = prices.size();

		if (k >= len / 2)
			return maxProfit_IV(prices);

		vector<vector<int>> dp(k + 1, vector<int>(len, 0));
		int cost = prices[0];

		//dp[i][j] means the maximum profile for at most i transactions by time j
		for (int i = 1; i <= k; i++) {
			cost = prices[0];

			for (int j = 1; j < len; j++) {
				dp[i][j] = max(dp[i][j - 1], prices[j] - cost);
				cost = min(cost, (prices[j] - dp[i - 1][j - 1]));
			}
		}

		return dp[k][len - 1];

/*
		if (k == 0 || prices.empty()) return 0;
		// Max profit by k transaction from 0 to i
		const int n = prices.size();
		if (k >= n / 2) return maxProfit_IV(prices);

		// balance - the balance with at most j transactions with item 0 to i
		// profit - the profit with at most j transactions with item 0 to i
		vector<int> balance(k + 1, INT_MIN), profit(k + 1);

		for (int i = 0; i < n; ++i) {
			for (int j = 1; j <= k; ++j) {
				balance[j] = max(profit[j - 1] - prices[i], balance[j]); // whether to buy at prices[i]
				profit[j] = max(balance[j] + prices[i], profit[j]); // whether to sell at prices[i]
			}
		}

		return profit[k];
*/
	}

	int Solution::maxProfit_IV(vector<int>& prices) {
		int profit = 0;
		for (int i = 1; i < (int)prices.size(); i++) {
			if (prices[i] > prices[i - 1])
				profit = profit + (prices[i] - prices[i - 1]);
		}

		return profit;
	}

	//72. Edit Distance Add to List
	/*
	This is a classic problem of Dynamic Programming. We define the state dp[i][j] to be the minimum number of operations to convert word1[0..i - 1] to word2[0..j - 1]. The state equations have two cases: the boundary case and the general case. Note that in the above notations, both i and j take values starting from 1.
	For the boundary case, that is, to convert a string to an empty string, it is easy to see that the mininum number of operations to convert word1[0..i - 1] to "" requires at least i operations (deletions). In fact, the boundary case is simply:
	dp[i][0] = i;
	dp[0][j] = j.
	Now let's move on to the general case, that is, convert a non-empty word1[0..i - 1] to another non-empty word2[0..j - 1]. Well, let's try to break this problem down into smaller problems (sub-problems). Suppose we have already known how to convert word1[0..i - 2] to word2[0..j - 2], which is dp[i - 1][j - 1]. Now let's consider word[i - 1] and word2[j - 1]. If they are euqal, then no more operation is needed and dp[i][j] = dp[i - 1][j - 1]. Well, what if they are not equal?
	If they are not equal, we need to consider three cases:
	Replace word1[i - 1] by word2[j - 1] (dp[i][j] = dp[i - 1][j - 1] + 1 (for replacement));
	Delete word1[i - 1] and word1[0..i - 2] = word2[0..j - 1] (dp[i][j] = dp[i - 1][j] + 1 (for deletion));
	Insert word2[j - 1] to word1[0..i - 1] and word1[0..i - 1] + word2[j - 1] = word2[0..j - 1] (dp[i][j] = dp[i][j - 1] + 1 (for insertion)).
	Make sure you understand the subtle differences between the equations for deletion and insertion. For deletion, we are actually converting word1[0..i - 2] to word2[0..j - 1], which costs dp[i - 1][j], and then deleting the word1[i - 1], which costs 1. The case is similar for insertion.
	Putting these together, we now have:
	dp[i][0] = i;
	dp[0][j] = j;
	dp[i][j] = dp[i - 1][j - 1], if word1[i - 1] = word2[j - 1];
	dp[i][j] = min(dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1, dp[i][j - 1] + 1), otherwise.
	The above state equations can be turned into the following code directly.
	*/
	int Solution::minDistance(string word1, string word2) {
		int m = word1.size(), n = word2.size();
		vector<int> dp(n + 1, 0);

		for (int i = 0; i <= n; i++)
			dp[i] = i;

		for (int i = 1; i <= m; i++) {
			int pre = dp[0];
			dp[0] = i;

			for (int j = 1; j <= n; j++) {
				int tmp = dp[j];

				if (word1[i - 1] == word2[j - 1])
					dp[j] = pre;
				else
					dp[j] = min(pre + 1, min(dp[j - 1] + 1, dp[j] + 1));

				pre = tmp;
			}
		}

		return dp[n];
		/*
		int m = word1.size(), n = word2.size();
		vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

		for(int i = 0; i <= m; i++)
		dp[i][0] = i;
		for(int j = 0; j <= n; j++)
		dp[0][j] = j;

		for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++) {
		if(word1[i-1] == word2[j-1])
		dp[i][j] = dp[i-1][j-1];
		else
		dp[i][j] = min(dp[i-1][j-1] + 1, min(dp[i-1][j] + 1, dp[i][j-1] + 1));
		}

		return dp[m][n];
		*/
	}

	//70. Climbing Stairs Add to List
	int Solution::climbStairs(int n) {
		if (n <= 2)
			return n;
		int n1 = 2, n2 = 1, ans = 0;

		for (int i = 3; i <= n; i++) {
			ans = n1 + n2;
			n2 = n1;
			n1 = ans;
		}
		return ans;
	}

	//450. Delete Node in a BST Add to List
	Solution::TreeNode* Solution::deleteNode(TreeNode* root, int key) {
		if (root == nullptr)
			return root;

		if (key < root->val)
			root->left = deleteNode(root->left, key);
		else if (key > root->val)
			root->right = deleteNode(root->right, key);
		else {
			if (root->right == nullptr)
				return root->left;
			else {
				TreeNode* minRight = findMinOfTree(root->right);
				root->val = minRight->val;
				root->right = deleteNode(root->right, minRight->val);
			}
		}

		return root;
	}

	Solution::TreeNode* Solution::findMinOfTree(TreeNode* node) {
		while (node->left != nullptr)
			node = node->left;
		return node;
	}

	//412. Fizz Buzz Add to List
	vector<string> Solution::fizzBuzz(int n) {
		vector<string> ans;
		for (int i = 1; i <= n; i++) {
			if (i % 15 == 0)
				ans.push_back("FizzBuzz");
			else if (i % 3 == 0)
				ans.push_back("Fizz");
			else if (i % 5 == 0)
				ans.push_back("Buzz");
			else
				ans.push_back(to_string(i));
		}

		return ans;
	}

	//12. Integer to Roman Add to List
	string Solution::intToRoman(int num) {
		vector<int> values = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
		vector<string> strs = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
		string ans = "";

		for (int i = 0; i < (int)values.size(); i++)
			while (num >= values[i]) {
				num -= values[i];
				ans.append(strs[i]);
			}

		return ans;
	}

	//42. Trapping Rain Water Add to List
	int Solution::trap(vector<int>& height) {
		int left = 0, right = height.size() - 1;
		int ans = 0, maxLeft = 0, maxRight = 0;

		while (left < right) {
			if (height[left] <= height[right]) {
				if (height[left] >= maxLeft)
					maxLeft = height[left];
				else
					ans += (maxLeft - height[left]);
				left++;
			}
			else {
				if (height[right] >= maxRight)
					maxRight = height[right];
				else
					ans += (maxRight - height[right]);
				right--;
			}
		}

		return ans;
	}

	//137. Single Number II Add to List
	int Solution::singleNumber_II(vector<int>& nums) {
		int x1 = 0, x2 = 0, mask = 0;

		for (auto num : nums) {
			x2 ^= x1 & num;
			x1 ^= num;
			mask = ~(x1 & x2);
			x1 &= mask;
			x2 &= mask;
		}

		return x1;
	}

	//319. Bulb Switcher Add to List
	int Solution::bulbSwitch(int n) {
		return (int)sqrt(n);
	}

	//461. Hamming Distance
	int Solution::hammingDistance(int x, int y) {
		return bitset<32>(x^y).count();
	}

	//150. Evaluate Reverse Polish Notation Add to List
	int Solution::evalRPN(vector<string>& tokens) {
		stack<int> nodes;
		for (auto token : tokens) {
			if (token == "+" || token == "-" || token == "*" || token == "/") {
				int b = nodes.top();
				nodes.pop();
				int a = nodes.top();
				nodes.pop();
				nodes.push(cal(a, b, token));
			}
			else
				nodes.push(stoi(token));
		}

		return nodes.top();
	}

	int Solution::cal(int a, int b, string token) {
		if (token == "+")
			return (a + b);
		else if (token == "-")
			return (a - b);
		else if (token == "*")
			return a * b;
		else if (token == "/")
			return a / b;
		return 0;
	}

	//115. Distinct Subsequences Add to List
	int Solution::numDistinct(string s, string t) {
		int row = t.size(), col = s.size();
		vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));

		for (int j = 0; j < col; j++)
			dp[0][j] = 1;
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++) {
				if (t[i] == s[j])
					dp[i + 1][j + 1] = dp[i][j] + dp[i + 1][j];
				else
					dp[i + 1][j + 1] = dp[i + 1][j];
			}

		return dp[row][col];
	}

	//64. Minimum Path Sum Add to List
	int Solution::minPathSum(vector<vector<int>>& grid) {
		int row = grid.size();
		if (row == 0)
			return 0;
		int col = grid[0].size();
		if (col == 0)
			return 0;

		for (int i = 1; i < row; i++)
			grid[i][0] += grid[i - 1][0];
		for (int j = 1; j < col; j++)
			grid[0][j] += grid[0][j - 1];

		for (int i = 1; i < row; i++)
			for (int j = 1; j < col; j++)
				grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);

		return grid[row - 1][col - 1];
	}

	//229. Majority Element II Add to List
	vector<int> Solution::majorityElement_II(vector<int>& nums) {
		int x = 0, y = 0, cx = 0, cy = 0;
		for (auto num : nums) {
			if (x == num)
				cx++;
			else if (y == num)
				cy++;
			else if (cx == 0) {
				x = num;
				cx = 1;
			}
			else if (cy == 0) {
				y = num;
				cy = 1;
			}
			else {
				cx--;
				cy--;
			}
		}

		int minLen = nums.size() / 3;
		vector<int> ans;
		cx = 0;
		cy = 0;
		for (auto num : nums) {
			if (x == num)
				cx++;
			else if (y == num)
				cy++;
		}

		if (cx > minLen)
			ans.push_back(x);
		if (cy > minLen)
			ans.push_back(y);

		return ans;
	}

	//343. Integer Break Add to List
	int Solution::integerBreak(int n) {
		vector<int> dp(n + 1, 1);

		if (n <= 2)
			return dp[n];

		dp[3] = 2;

		for (int i = 4; i <= n; i++) {
			for (int j = 2; j * 2 <= i; j++) {
				int tmp = max(j, dp[j]) * max(i - j, dp[i - j]);
				dp[i] = max(tmp, dp[i]);
			}
		}

		return dp[n];
		/*
		if(n <= 2)
		return 1;
		if(n == 3)
		return 2;
		if(n == 4)
		return 4;

		int ans = 1;
		while(n >= 5 ) {
		ans *= 3;
		n -= 3;
		}

		return ans * n;
		*/
	}

	//62. Unique Paths 
	int Solution::uniquePaths(int m, int n) {
		if (m > n)
			return uniquePaths(n, m);
		vector<int> cur(n, 1);
		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++)
				cur[j] += cur[j - 1];

		return cur[n - 1];
		/*
		if(m > n)
		return uniquePaths(n, m);
		vector<int> cur(n, 1), pre(n, 1);
		for(int i = 1; i < m; i++) {
		for(int j = 1; j < n; j++)
		cur[j] = cur[j-1] + pre[j];
		swap(cur, pre);
		}

		return pre[n-1];
		*/
		/*
		vector<vector<int>> dp(m, vector<int>(n, 1));

		for(int i = 1; i < m; i++)
		for(int j = 1; j < n; j++)
		dp[i][j] = dp[i-1][j] + dp[i][j-1];

		return dp[m-1][n-1];
		*/
	}

	//243. Shortest Word Distance 
	int Solution::shortestDistance(vector<string>& words, string word1, string word2) {
		int p1 = 0, p2 = 0, ans = INT_MAX;
		for (int i = 0; i < (int)words.size(); i++) {
			if (words[i].compare(word1) == 0)
				p1 = i + 1;
			if (words[i].compare(word2) == 0)
				p2 = i + 1;
			if (p1 && p2)
				if (abs(p2 - p1) < ans)
					ans = abs(p2 - p1);
		}

		return ans;
	}

	//244. Shortest Word Distance II 
	void Solution::WordDistance(vector<string> words) {
		for (int i = 0; i < (int)words.size(); i++)
			hashmap_244[words[i]].push_back(i);
	}

	int Solution::shortest(string word1, string word2) {
		int i = 0, j = 0, dist = INT_MAX;
		if (hashmap_244[word1].size() == 1 && hashmap_244[word2].size() == 1)
			return abs(hashmap_244[word1][0] - hashmap_244[word2][0]);
		while (i < (int)hashmap_244[word1].size() && j < (int)hashmap_244[word2].size()) {
			dist = min(dist, abs(hashmap_244[word1][i] - hashmap_244[word2][j]));
			hashmap_244[word1][i] < hashmap_244[word2][j] ? i++ : j++;
		}

		return dist;
	}

	//Test of Sudoku
	bool Solution::Sudoku(vector<vector<int>> nums) {
		if (nums.empty() || nums[0].empty())
			return false;
	    
		int m = nums.size(), n = nums[0].size();
		if (m != n)
			return false;
	    
		vector<unordered_set<int>> col(n);

		for (int i = 0; i < m; i++) {
			unordered_set<int> row;
			for (int j = 0; j < n; j++) {
				if (row.insert(nums[i][j]).second == false)
					return false;
				if (col[j].insert(nums[i][j]).second == false)
					return false;
			}
		}

		return true;
	}

	// 146. LRU Cache 
	void Solution::LRUCache(int capacity) {
		mycapacity_146 = capacity;
	}

	int Solution::get_146(int key) {
		auto it = hashmap_146.find(key);
		if (it == hashmap_146.end())
			return -1;
		mylist_146.splice(mylist_146.begin(), mylist_146, it->second);
		it->second = mylist_146.begin();
		return it->second->second;
	}

	void Solution::put_146(int key, int value) {
		if (get_146(key) != -1)
			mylist_146.front().second = value;
		else {
			if (hashmap_146.size() == mycapacity_146) {
				hashmap_146.erase(mylist_146.back().first);
				mylist_146.pop_back();
			}
			mylist_146.push_front(pair<int, int>(key, value));
			hashmap_146[key] = mylist_146.begin();
		}
	}

	// 300. Longest Increasing Subsequence 
	/*
	1. If A[i] is smallest among all end
	candidates of active lists, we will start
	new active list of length 1.
	2. If A[i] is largest among all end candidates of
	active lists, we will clone the largest active
	list, and extend it by A[i].

	3. If A[i] is in between, we will find a list with
	largest end element that is smaller than A[i].
	Clone and extend this list by A[i]. We will discard all
	other lists of same length as that of this modified list.

	It will be clear with an example, let us take example from wiki {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15}.
	A[0] = 0. Case 1. There are no active lists, create one.
	0.
	-----------------------------------------------------------------------------
	A[1] = 8. Case 2. Clone and extend.
	0.
	0, 8.
	-----------------------------------------------------------------------------
	A[2] = 4. Case 3. Clone, extend and discard.
	0.
	0, 4.
	0, 8. Discarded
	-----------------------------------------------------------------------------
	A[3] = 12. Case 2. Clone and extend.
	0.
	0, 4.
	0, 4, 12.
	-----------------------------------------------------------------------------
	A[4] = 2. Case 3. Clone, extend and discard.
	0.
	0, 2.
	0, 4. Discarded.
	0, 4, 12.
	-----------------------------------------------------------------------------
	A[5] = 10. Case 3. Clone, extend and discard.
	0.
	0, 2.
	0, 2, 10.
	0, 4, 12. Discarded.
	-----------------------------------------------------------------------------
	A[6] = 6. Case 3. Clone, extend and discard.
	0.
	0, 2.
	0, 2, 6.
	0, 2, 10. Discarded.
	-----------------------------------------------------------------------------
	A[7] = 14. Case 2. Clone and extend.
	0.
	0, 2.
	0, 2, 6.
	0, 2, 6, 14.
	-----------------------------------------------------------------------------
	A[8] = 1. Case 3. Clone, extend and discard.
	0.
	0, 1.
	0, 2. Discarded.
	0, 2, 6.
	0, 2, 6, 14.
	-----------------------------------------------------------------------------
	A[9] = 9. Case 3. Clone, extend and discard.
	0.
	0, 1.
	0, 2, 6.
	0, 2, 6, 9.
	0, 2, 6, 14. Discarded.
	-----------------------------------------------------------------------------
	A[10] = 5. Case 3. Clone, extend and discard.
	0.
	0, 1.
	0, 1, 5.
	0, 2, 6. Discarded.
	0, 2, 6, 9.
	-----------------------------------------------------------------------------
	A[11] = 13. Case 2. Clone and extend.
	0.
	0, 1.
	0, 1, 5.
	0, 2, 6, 9.
	0, 2, 6, 9, 13.
	-----------------------------------------------------------------------------
	A[12] = 3. Case 3. Clone, extend and discard.
	0.
	0, 1.
	0, 1, 3.
	0, 1, 5. Discarded.
	0, 2, 6, 9.
	0, 2, 6, 9, 13.
	-----------------------------------------------------------------------------
	A[13] = 11. Case 3. Clone, extend and discard.
	0.
	0, 1.
	0, 1, 3.
	0, 2, 6, 9.
	0, 2, 6, 9, 11.
	0, 2, 6, 9, 13. Discarded.
	-----------------------------------------------------------------------------
	A[14] = 7. Case 3. Clone, extend and discard.
	0.
	0, 1.
	0, 1, 3.
	0, 1, 3, 7.
	0, 2, 6, 9. Discarded.
	0, 2, 6, 9, 11.
	----------------------------------------------------------------------------
	A[15] = 15. Case 2. Clone and extend.
	0.
	0, 1.
	0, 1, 3.
	0, 1, 3, 7.
	0, 2, 6, 9, 11.
	0, 2, 6, 9, 11, 15. <-- LIS List
	----------------------------------------------------------------------------
	*/
	int Solution::lengthOfLIS(vector<int>& nums) {
		vector<int> res;
		for (int i = 0; i < (int)nums.size(); i++) {
			auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
			if (it == res.end()) res.push_back(nums[i]);
			else *it = nums[i];
		}
		return res.size();
	}

	//452. Minimum Number of Arrows to Burst Balloons 
	// First, we sort balloons by increasing points.end (if ends are the same, then by increasing of points.start). 
	// Every time arrow shot points.end, say, points[i].second. If next balloon.start <= points[i].second, it is also shot, 
	// thus we continue.
	const bool Solution::cmpArrow(pair<int, int> a, pair<int, int> b) {
		return a.second < b.second;
	}

	int Solution::findMinArrowShots(vector<pair<int, int>>& points) {
		if (points.empty())
			return 0;

		sort(points.begin(), points.end(), cmpArrow);

		int arrow = points[0].second, count = 1;
		for (int i = 1; i < (int)points.size(); i++) {
			if (points[i].first <= arrow)
				continue;
			arrow = points[i].second;
			count++;
		}

		return count;
	}

	//8. String to Integer (atoi) 
	int Solution::myAtoi(string str) {
		long result = 0;
		int indicator = 1;
		for (int i = 0; i<(int)str.size();)
		{
			i = str.find_first_not_of(' ');
			if (str[i] == '-' || str[i] == '+')
				indicator = (str[i++] == '-') ? -1 : 1;
			while ('0' <= str[i] && str[i] <= '9')
			{
				result = result * 10 + (str[i++] - '0');
				if (result*indicator >= INT_MAX) return INT_MAX;
				if (result*indicator <= INT_MIN) return INT_MIN;
			}
			return result*indicator;
		}
		return 0;
	}

	//238. Product of Array Except Self 
	vector<int> Solution::productExceptSelf(vector<int>& nums) {
		vector<int> ans(nums.size(), 1);
		for (int i = 1; i < (int)nums.size(); i++)
			ans[i] = ans[i - 1] * nums[i - 1];

		int pr = 1;
		for (int i = nums.size() - 2; i >= 0; i--) {
			pr *= nums[i + 1];
			ans[i] = ans[i] * pr;
		}

		return ans;
	}

	//162. Find Peak Element 
	int Solution::findPeakElement(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;

		while (left < right) {
			int mid = left + (right - left) / 2;
			//here mid+1 is always less than nums.size()
			if (nums[mid] > nums[mid + 1])
				right = mid;
			else
				left = mid + 1;
		}

		return left;
		/*
		for(int i = 0; i < (int)(nums.size() - 1); i++)
		if(nums[i] > nums[i+1])
		return i;
		return nums.size() - 1;
		*/
	}

	//285. Inorder Successor in BST 
	// doesn't work if there is duplicate values.

	Solution::TreeNode* Solution::inorderSuccessor(TreeNode* root, TreeNode* p) {
		TreeNode* ans = nullptr;
		while (root) {
			// search for the first value which is bigger than p and store it with ans
			if (root->val > p->val) {
				ans = root;
				root = root->left;
			}
			else
				root = root->right;
		}

		return ans;
	}

	//4. Median of Two Sorted Arrays 

	/*
	To solve this problem, we need to understand "What is the use of median". In statistics, the median is used for dividing a set into two equal length subsets, that one subset is always greater than the other. If we understand the use of median for dividing, we are very close to the answer.
	First let's cut A into two parts at a random position i:
	left_A             |        right_A
	A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[m-1]
	Since A has m elements, so there are m+1 kinds of cutting( i = 0 ~ m ). And we know: len(left_A) = i, len(right_A) = m - i . Note: when i = 0 , left_A is empty, and when i = m , right_A is empty.
	With the same way, cut B into two parts at a random position j:
	left_B             |        right_B
	B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[n-1]
	Put left_A and left_B into one set, and put right_A and right_B into another set. Let's name them left_part and right_part :
	left_part          |        right_part
	A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[m-1]
	B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[n-1]
	If we can ensure:
	1) len(left_part) == len(right_part)
	2) max(left_part) <= min(right_part)
	then we divide all elements in {A, B} into two parts with equal length, and one part is always greater than the other. Then median = (max(left_part) + min(right_part))/2.
	To ensure these two conditions, we just need to ensure:
	(1) i + j == m - i + n - j (or: m - i + n - j + 1)
	if n >= m, we just need to set: i = 0 ~ m, j = (m + n + 1)/2 - i
	(2) B[j-1] <= A[i] and A[i-1] <= B[j]
	ps.1 For simplicity, I presume A[i-1],B[j-1],A[i],B[j] are always valid even if i=0/i=m/j=0/j=n . I will talk about how to deal with these edge values at last.
	ps.2 Why n >= m? Because I have to make sure j is non-nagative since 0 <= i <= m and j = (m + n + 1)/2 - i. If n < m , then j may be nagative, that will lead to wrong result.
	So, all we need to do is:
	Searching i in [0, m], to find an object `i` that:
	B[j-1] <= A[i] and A[i-1] <= B[j], ( where j = (m + n + 1)/2 - i )
	And we can do a binary search following steps described below:
	<1> Set imin = 0, imax = m, then start searching in [imin, imax]

	<2> Set i = (imin + imax)/2, j = (m + n + 1)/2 - i

	<3> Now we have len(left_part)==len(right_part). And there are only 3 situations
	that we may encounter:
	<a> B[j-1] <= A[i] and A[i-1] <= B[j]
	Means we have found the object `i`, so stop searching.
	<b> B[j-1] > A[i]
	Means A[i] is too small. We must `ajust` i to get `B[j-1] <= A[i]`.
	Can we `increase` i?
	Yes. Because when i is increased, j will be decreased.
	So B[j-1] is decreased and A[i] is increased, and `B[j-1] <= A[i]` may
	be satisfied.
	Can we `decrease` i?
	`No!` Because when i is decreased, j will be increased.
	So B[j-1] is increased and A[i] is decreased, and B[j-1] <= A[i] will
	be never satisfied.
	So we must `increase` i. That is, we must ajust the searching range to
	[i+1, imax]. So, set imin = i+1, and goto <2>.
	<c> A[i-1] > B[j]
	Means A[i-1] is too big. And we must `decrease` i to get `A[i-1]<=B[j]`.
	That is, we must ajust the searching range to [imin, i-1].
	So, set imax = i-1, and goto <2>.
	When the object i is found, the median is:
	max(A[i-1], B[j-1]) (when m + n is odd)
	or (max(A[i-1], B[j-1]) + min(A[i], B[j]))/2 (when m + n is even)
	Now let's consider the edges values i=0,i=m,j=0,j=n where A[i-1],B[j-1],A[i],B[j] may not exist. Actually this situation is easier than you think.
	What we need to do is ensuring that max(left_part) <= min(right_part). So, if i and j are not edges values(means A[i-1],B[j-1],A[i],B[j] all exist), then we must check both B[j-1] <= A[i] and A[i-1] <= B[j]. But if some of A[i-1],B[j-1],A[i],B[j] don't exist, then we don't need to check one(or both) of these two conditions. For example, if i=0, then A[i-1] doesn't exist, then we don't need to check A[i-1] <= B[j]. So, what we need to do is:
	Searching i in [0, m], to find an object `i` that:
	(j == 0 or i == m or B[j-1] <= A[i]) and
	(i == 0 or j == n or A[i-1] <= B[j])
	where j = (m + n + 1)/2 - i
	And in a searching loop, we will encounter only three situations:
	<a> (j == 0 or i == m or B[j-1] <= A[i]) and
	(i == 0 or j = n or A[i-1] <= B[j])
	Means i is perfect, we can stop searching.

	<b> j > 0 and i < m and B[j - 1] > A[i]
	Means i is too small, we must increase it.

	<c> i > 0 and j < n and A[i - 1] > B[j]
	Means i is too big, we must decrease it.
	Thank @Quentin.chen , him pointed out that: i < m ==> j > 0 and i > 0 ==> j < n . Because:
	m <= n, i < m ==> j = (m+n+1)/2 - i > (m+n+1)/2 - m >= (2*m+1)/2 - m >= 0
	m <= n, i > 0 ==> j = (m+n+1)/2 - i < (m+n+1)/2 <= (2*n+1)/2 <= n
	So in situation <b> and <c>, we don't need to check whether j > 0 and whether j < n.
	*/
	double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size(), n = nums2.size();
		if (m > n) return findMedianSortedArrays(nums2, nums1);
		int minidx = 0, maxidx = m, i, j, num1, mid = (m + n + 1) / 2, num2;
		while (minidx <= maxidx)
		{
			i = minidx + (maxidx - minidx) / 2;
			j = mid - i;
			if (i<m && j>0 && nums2[j - 1] > nums1[i]) minidx = i + 1;
			else if (i>0 && j<n && nums2[j] < nums1[i - 1]) maxidx = i - 1;
			else
			{
				if (i == 0) num1 = nums2[j - 1];
				else if (j == 0) num1 = nums1[i - 1];
				else num1 = max(nums1[i - 1], nums2[j - 1]);
				break;
			}
		}
		if ((m + n) & 1) return num1;
		if (i == m) num2 = nums2[j];
		else if (j == n) num2 = nums1[i];
		else num2 = min(nums1[i], nums2[j]);
		return (num1 + num2) / 2.;

	}
/*
auto cmp1 = [&](int a, int b) {return a > b; };
auto cmp = [&](pair<int, int> a, pair<int, int> b) {return distance(a, ref) < distance(b, ref); };
pair<int, int> p1 = { 1,1 };
pair<int, int> p2 = { 2,2 };
pair<int, int> p4 = { 4, 4 };
priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> heap(cmp);
int tmpd = distance(p1, ref);
heap.push(p1);
tmpd = distance(p2, ref);
heap.push(p2);
tmpd = distance(p4, ref);
heap.push(p4);
pair<int, int> tmpp = heap.top();
heap.pop();
tmpp = heap.top();
heap.pop();
tmpp = heap.top();
heap.pop();

return set<int>();
*/
	// MS OTS 02/07/2017
	std::set<pair<int,int>> Solution::ClosestKPoints(std::set<pair<int, int>> allpoints, pair<int, int> ref, int k) {
		auto cmp = [&](pair<int, int> a, pair<int, int> b) {return distance(a, ref) < distance(b, ref); };
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> heap(cmp);
		for (auto p : allpoints) {
			heap.push(p);
			if ((int) heap.size() > k)
				heap.pop();
		}

		set<pair<int, int>> ans;
		while (!heap.empty()) {
			ans.insert(heap.top());
			heap.pop();
		}
		return ans;
	}

	int Solution::distance(pair<int, int>p1, pair<int, int>p2) {
		return (int)sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
	}

	//147. Insertion Sort List 
	Solution::ListNode* Solution::insertionSortList(ListNode* head) {
		ListNode newHead(-1);
		while (head) {
			ListNode *p = head, *q = &newHead;
			head = head->next;
			while (q->next != nullptr && q->next->val <= p->val)
				q = q->next;
			p->next = q->next;
			q->next = p;
		}

		return newHead.next;
	}

	//35. Search Insert Position 
	int Solution::searchInsert(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;

			if (nums[mid] < target)
				left = mid + 1;
			else
				right = mid - 1;
		}

		return left;
	}

	// 380. Insert Delete GetRandom O(1) 
	void Solution::RandomizedSet() {

	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool Solution::insert(int val) {
		if (hashmap_380.find(val) != hashmap_380.end())
			return false;

		hashmap_380[val] = v_380.size();
		v_380.push_back(val);
		return true;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool Solution::remove(int val) {
		if (hashmap_380.find(val) == hashmap_380.end())
			return false;

		int last = v_380.size() - 1;
		hashmap_380[v_380[last]] = hashmap_380[val];
		v_380[hashmap_380[val]] = v_380[last];
		v_380.pop_back();
		hashmap_380.erase(val);

		return true;
	}

	/** Get a random element from the set. */
	int Solution::getRandom() {
		minstd_rand0 generator((unsigned int)time(NULL));
		int r = generator();
		return v_380[r % v_380.size()];
	}

	//516. Longest Palindromic Subsequence 
	int Solution::longestPalindromeSubseq(string s) {
		if (s.empty())
			return 0;
		int n = s.size();
		vector<vector<int>> dp(n, vector<int>(n, 0));
		for (int i = n - 1; i >= 0; i--) {
			dp[i][i] = 1;
			for (int j = i + 1; j < n; j++) {
				if (s[i] == s[j])
					dp[i][j] = dp[i + 1][j - 1] + 2;
				else
					dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
			}
		}

		return dp[0][n - 1];
	}

	//127. Word Ladder 
	int Solution::ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> words(wordList.begin(), wordList.end());
		queue<string> q;
		q.push(beginWord);
		for (int depth = 1; q.empty() == false; depth++) {
			for (int size = q.size(); size > 0; size--) {
				string w = q.front();
				q.pop();
				if (w.compare(endWord) == 0) return depth;
				for (int i = 0; i < (int)w.size(); i++) {
					string str = w;
					for (int j = 0; j < 26; j++) {
						str[i] = 'a' + j;
						if (words.erase(str))
							q.push(str);
					}
				}
			}
		}

		return 0;
	}

	//240. Search a 2D Matrix II 
    /* We start search the matrix from top right corner, initialize the current position to top right corner, 
	if the target is greater than the value in current position, 
	then the target can not be in entire row of current position because the row is sorted, 
	if the target is less than the value in current position, 
	then the target can not in the entire column because the column is sorted too. 
	We can rule out one row or one column each time, so the time complexity is O(m+n).
	*/
	bool Solution::searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty())
			return false;
		int col = matrix[0].size() - 1, row = 0;
		while (row < (int)matrix.size() && col >= 0) {
			if (matrix[row][col] == target)
				return true;
			else if (matrix[row][col] < target)
				row++;
			else
				col--;
		}

		return false;
	}

	bool Solution::binarySearch(vector<vector<int>>& matrix, int &starti, int &startj, int endi, int endj, bool row, int target) {
		if (starti < 0 || startj < 0 || endi >= (int)matrix.size() || endj >= (int)matrix[0].size())
			return false;

		int r = 1, c = 0;
		if (!row)
			swap(r, c);

		while ((row && startj <= endj) || (!row && starti <= endi)) {
			int midi = starti + c * (endi - starti) / 2;
			int midj = startj + r * (endj - startj) / 2;
			if (matrix[midi][midj] == target)
				return true;
			else if (matrix[midi][midj] < target) {
				starti = midi + 1 * c;
				startj = midj + 1 * r;
			}
			else {
				endi = midi - 1 * c;
				endj = midj - 1 * r;
			}
		}

		starti -= 1 * c; 
		startj -= 1 * r;
		return false;
	}

	//239. Sliding Window Maximum 
	vector<int> Solution::maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> ans;
		deque<int> q;
		for (int i = 0; i < (int)nums.size(); i++) {
			if (!q.empty() && q.front() < i - (k - 1))
				q.pop_front();
			while (!q.empty() && nums[q.back()] <= nums[i])
				q.pop_back();
			q.push_back(i);
			if (i >= k - 1)
				ans.push_back(nums[q.front()]);
		}

		return ans;
	}

	//17. Letter Combinations of a Phone Number 
	vector<string> Solution::letterCombinations(string digits) {
		if (digits.empty())
			return vector<string>();

		vector<string> map = { "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		deque<string> q;
		q.push_back("");
		for (auto d : digits) {
			int id = d - '0';
			for (int size = q.size(); size > 0; size--) {
				string str = q.front();
				q.pop_front();
				for (auto c : map[id])
					q.push_back(str + c);
			}
		}

		return vector<string>(q.begin(), q.end());
	}

	//49. Group Anagrams 
	vector<vector<string>> Solution::groupAnagrams_49(vector<string>& strs) {
		vector<vector<string>> ans;
		unordered_map<string, unordered_multiset<string>> hashmap;

		for (auto str : strs)
			hashmap[convert_49(str)].insert(str);

		for (auto h : hashmap)
			ans.push_back(vector<string>(h.second.begin(), h.second.end()));

		return ans;
	}

	string Solution::convert_49(string& str) {
		vector<int> count(26, 0);
		string ans = "";
		for (auto c : str)
			count[c - 'a']++;

		for (int i = 0; i < 26; i++)
			if (count[i] != 0)
				ans += to_string(count[i]) + char(i);

		return ans;
	}

	//199. Binary Tree Right Side View 
	vector<int> Solution::rightSideView(TreeNode* root) {
		vector<int> ans;
		rightSideView(root, ans, 1);
		return ans;
	}
	void Solution::rightSideView(TreeNode*& root, vector<int>& ans, int depth) {
		if (root == nullptr)
			return;
		if (depth > (int)ans.size())
			ans.push_back(root->val);

		rightSideView(root->right, ans, depth + 1);
		rightSideView(root->left, ans, depth + 1);
	}

	//KMP table
	/*
	Every number belongs to corresponding prefix("a", "ab", "aba", ...) and for each prefix it represents length of longest suffix of this string that matches prefix.We do not count whole string as suffix or prefix here, it is called self - suffix and self - prefix(at least in Russian, not sure about English terms).
		So we have string "ababaca".Let's look at it. KMP computes Prefix Function for every non-empty prefix. Let's define P(i) as Prefix function of i - th prefix.Bold part shows matching prefix and italic part shows matching suffix.Parts can overlap.
# | String | P(#) | Longest matching prefix-suffix
		0 | "a" | 0 | ""
		1 | "ab" | 0 | ""
		2 | "aba" | 1 | "a" --a b a
		3 | "abab" | 2 | "ab" --ab ab
		4 | "ababa" | 3 | "aba" --ab a ba
		5 | "ababac" | 0 | ""
		6 | "ababaca" | 1 | "a" --a babac a
		Simple C++ code that computes Prefix function of string S :
		*/
	vector<int> Solution::PrefixFunction(string S) {
		vector<int> p(S.size());
		int j = 0;
		for (int i = 1; i < (int)S.size(); i++) {
			while (j > 0 && S[j] != S[i])
				j = p[j - 1];

			if (S[j] == S[i])
				j++;
			p[i] = j;
		}
		return p;
	}

	//508. Most Frequent Subtree Sum 
	vector<int> Solution::findFrequentTreeSum(TreeNode* root) {
		vector<int> ans;
		unordered_map<int, int> hashmap;

		findFrequentTreeSum(root, hashmap);

		int max = 0;
		for (auto m : hashmap)
			if (m.second > max)
				max = m.second;
		for (auto m : hashmap)
			if (m.second == max)
				ans.push_back(m.first);

		return ans;
	}

	int Solution::findFrequentTreeSum(TreeNode* root, unordered_map<int, int>& hashmap) {
		if (root == nullptr)
			return 0;
		int sum = findFrequentTreeSum(root->left, hashmap) + findFrequentTreeSum(root->right, hashmap) + root->val;
		hashmap[sum]++;
		return sum;
	}

	//459. Repeated Substring Pattern 
	/*
	First, we build the KMP table.
	Roughly speaking, dp[i+1] stores the maximum number of characters that the string is repeating itself up to position i.
	Therefore, if a string repeats a length 5 substring 4 times, then the last entry would be of value 15.
	To check if the string is repeating itself, we just need the last entry to be non-zero and str.size() to divide (str.size()-last entry).
	*/
	bool Solution::repeatedSubstringPattern(string str) {
		int i = 1, j = 0, n = str.size();
		vector<int> dp(n + 1, 0);
		while (i < (int)str.size()) {
			if (str[i] == str[j]) dp[++i] = ++j;
			else if (j == 0) i++;
			else j = dp[j];
		}
		return dp[n] && dp[n] % (n - dp[n]) == 0;

	}

	//61. Rotate List 
	Solution::ListNode* Solution::rotateRight(ListNode* head, int k) {
		if (head == nullptr)
			return head;

		int len = 1;
		ListNode* p = head;
		while (p->next) {
			len++;
			p = p->next;
		}
		p->next = head;
		k = len - k % len;
		while (k--)
			p = p->next;
		head = p->next;
		p->next = nullptr;

		return head;
	}

	//344. Reverse String 
	string Solution::reverseString(string s) {
		int i = 0, j = s.size() - 1;
		while (i < j) {
			swap(s[i++], s[j--]);
		}

		return s;
	}

	//355. Design Twitter 
	/** Initialize your data structure here. */
	void Solution::Twitter() {
	}

	/** Compose a new tweet. */
	void Solution::postTweet(int userId, int tweetId) {
		tweet[userId].push_front(pair<int, time_t>(tweetId, time(NULL)));
		follower[userId].insert(userId);
	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> Solution::getNewsFeed(int userId) {
		vector<pair<int,time_t>> ans;
		vector<int> res;
		auto cmp = [&](pair<int, time_t> a, pair<int, time_t> b) {return a.second > b.second; };
		priority_queue<pair<int, time_t>, vector<pair<int, time_t>>, decltype(cmp)> heap(cmp);
		auto it = follower.find(userId);
		if (it == follower.end())
			return res;
		for (auto user : it->second) {
			int count = 0;
			for (auto it = tweet[user].begin(); count < 10 && it != tweet[user].end(); it++, count++) {
				heap.push(*it);
				if (heap.size() > 10)
					heap.pop();
			}
		}
		while (!heap.empty()) {
			ans.push_back(heap.top());
			heap.pop();
		}
		sort(ans.begin(), ans.end(), cmp);
		for (auto a : ans)
			res.push_back(a.first);
		return res;
	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void Solution::follow(int followerId, int followeeId) {
		follower[followerId].insert(followeeId);
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void Solution::unfollow(int followerId, int followeeId) {
		if (followerId == followeeId)
			return;
		if (follower.find(followerId) != follower.end())
			follower[followerId].erase(followeeId);
	}

	//132. Palindrome Partitioning 
	/*
	Calculate and maintain 2 DP states:
	pal[i][j] , which is whether s[i..j] forms a pal
	d[i], which
	is the minCut for s[i..n-1]
	Once we comes to a pal[i][j]==true:
	if j==n-1, the string s[i..n-1] is a Pal, minCut is 0, d[i]=0;
	else: the current cut num (first cut s[i..j] and then cut the rest
	s[j+1...n-1]) is 1+d[j+1], compare it to the exisiting minCut num
	d[i], repalce if smaller.
	d[0] is the answer.
	*/
	int Solution::minCut(string s) {
		if (s.empty())
			return 0;

		int n = s.size();
		vector<vector<bool>> pal(n, vector<bool>(n, false));
		vector<int> cut(n, 0);

		for (int i = n - 1; i >= 0; i--) {
			cut[i] = n - i - 1;
			for (int j = i; j < n; j++) {
				if (s[i] == s[j] && (j - i < 2 || pal[i + 1][j - 1])) {
					pal[i][j] = true;
					if (j == n - 1)
						cut[i] = 0;
					else if (cut[i] > cut[j + 1] + 1)
						cut[i] = cut[j + 1] + 1;
				}
			}
		}

		return cut[0];
	}

	//76. Minimum Window Substring
	string Solution::minWindow(string s, string t) {
		vector<int> map(128, 0);
		int counter = t.size(), begin = 0, end = 0, d = s.size(), head = 0;
		bool found = false;

		// Statistic for count of char in t
		// counter represents the number of chars of t to be found in s.
		for (auto c : t)
			map[c]++;

		// Move end to find a valid window.
		while (end<(int)s.size()) {
			// If char in s exists in t, decrease counter
			if (map[s[end]] > 0)
				counter--; //in t

						   // Decrease m[s[end]]. If char does not exist in t, m[s[end]] will be negative.
			map[s[end]]--;
			end++;

			// When we found a valid window, move start to find smaller window.
			while (counter == 0) { //valid
				found = true;

				// When char exists in t, increase counter.
				if (map[s[begin]] == 0) {
					counter++;  //make it invalid
					if (end - begin < d) {
						d = end - begin;
						head = begin;
					};
				}
				map[s[begin]]++;
				begin++;
			}
		}
		return found ? s.substr(head, d) : "";

/*
		if (s.empty() || t.empty())
			return "";

		vector<int> sv(128, 0), tv(128, 0);
		for (auto c : t)
			tv[c]++;

		int start = 0, end = 0, ans = 0, pos = 0, sn = s.size(), tn = t.size();

		for (; start < sn; start++)
			if (tv[s[start]] > 0)
				break;
		end = start;
		while (end < sn) {
			sv[s[end++]]++;
			if (IsAnagram(sv, tv)) {
				shrinkWindow(s, sv, tv, start, end);
				ans = end - start;
				pos = start;
				break;
			}
		}

		while (end < sn) {
			sv[s[end++]]++;
			sv[s[start++]]--;
			if (IsAnagram(sv, tv)) {
				shrinkWindow(s, sv, tv, start, end);
				if (ans > end - start) {
					ans = end - start;
					pos = start;
				}
			}
			if (ans == tn)
				break;
		}

		return s.substr(pos, ans);
*/
	}

	bool Solution::IsAnagram(vector<int>& sv, vector<int>& tv) {
		for (int i = 0; i < 128; i++)
			if (sv[i] < tv[i])
				return false;

		return true;
	}

	void Solution::shrinkWindow(string &s, vector<int> &sv, vector<int> &tv, int &start, int&end) {
		while (start < end) {
			sv[s[start++]]--;
			if (!IsAnagram(sv, tv)) {
				start--;
				sv[s[start]]++;
				return;
			}
		}
	}

	//test of sequence
	int Solution::testofsequence(int a, int b) {
		return a + b;
	}

	//159. Longest Substring with At Most Two Distinct Characters
	int Solution::lengthOfLongestSubstringTwoDistinct(string s) {
		vector<int> dict(128, 0);

		int count = 0, start = 0, end = 0, len = 0;

		while (end < (int)s.size()) {
			if (dict[s[end]] == 0)
				count++;
			dict[s[end]]++;
			end++;

			while (count > 2) {
				if (dict[s[start]] == 1)
					count--;
				dict[s[start]]--;
				start++;
			}

			len = max(len, end - start);
		}

		return len;
	}

	//340. Longest Substring with At Most K Distinct Characters 
	int Solution::lengthOfLongestSubstringKDistinct(string s, int k) {
		vector<int> dict(128, 0);

		int count = 0, start = 0, end = 0, len = 0;

		while (end < (int)s.size()) {
			if (dict[s[end]] == 0)
				count++;

			dict[s[end]]++;
			end++;

			if (count > k) {
				if (dict[s[start]] == 1)
					count--;
				dict[s[start]]--;
				start++;
			}

			len = max(len, end - start);
		}

		return len;
	}

	//395. Longest Substring with At Least K Repeating Characters
	int Solution::longestSubstring(string s, int k) {
		/*
		if(s.size() == 0 || k > s.size())   return 0;
		if(k <= 1)  return s.size();

		vector<int> dict(128, 0);
		for(int i = 0; i < s.size(); i++){
		dict[s[i]]++;
		}

		int idx =0;
		while(idx <s.size() && dict[s[idx]] >= k)    idx++;
		if(idx == s.size()) return s.size();

		int left = longestSubstring(s.substr(0 , idx) , k);
		int right = longestSubstring(s.substr(idx+1) , k);

		return max(left, right);
		*/
		if (s.empty() || k <= 1)
			return s.size();

		return longestSubstring(s, 0, s.size() - 1, k);
	}

	int Solution::longestSubstring(string &s, int left, int right, int k) {
		int len = right - left + 1;
		if (len < k)
			return 0;

		vector<int> dict(26, 0);
		for (int i = left; i <= right; i++)
			dict[s[i]-'a']++;

		for (int i = left; i <= right; i++)
			if (dict[s[i]-'a'] < k)
				return max(longestSubstring(s, left, i - 1, k), longestSubstring(s, i + 1, right, k));

		return len;
	}
	//276. Paint Fence
	int Solution::numWays(int n, int k) {
		if (n <= 0)
			return 0;
		else if (n == 1)
			return k;
		if (k <= 0)
			return 0;
		if (k == 1) {
			if (n > 2)
				return 0;
			else if (n == 2)
				return 1;
		}

		int sameColor = k, difColor = k * (k - 1);
		for (int i = 2; i < n; i++) {
			int tmp = difColor;
			difColor = (sameColor + difColor) * (k - 1);
			sameColor = tmp;
		}

		return sameColor + difColor;
	}

	//30. Substring with Concatenation of All Words 
	vector<int> Solution::findSubstring(string s, vector<string>& words) {
		unordered_map<string, int> hashmap;
		for (auto w : words)
			hashmap[w]++;

		vector<int> ans;
		int len = words[0].size(), num = words.size(), n = s.size();

		for (int i = 0; i < n - num * len + 1; i++) {
			unordered_map<string, int> count;
			int j = 0;
			for (; j < num; j++) {
				string str = s.substr(i + j * len, len);
				if (hashmap.find(str) != hashmap.end()) {
					count[str]++;
					if (count[str] > hashmap[str])
						break;
				}
				else
					break;
			}
			if (j == num)
				ans.push_back(i);
		}

		return ans;
	}

	//10. Regular Expression Matching
	bool Solution::isMatch(string s, string p) {
		vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
		int m = s.size(), n = p.size();
		dp[0][0] = true;
		for (int j = 2; j <= n; j++)
			if (p[j - 1] == '*')
				dp[0][j] = dp[0][j - 2];

		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (isMatch(s[i - 1], p[j - 1]))
					dp[i][j] = dp[i - 1][j - 1];
				else if (j > 1 && p[j - 1] == '*') {
					dp[i][j] = dp[i][j - 2];
					if (isMatch(s[i - 1], p[j - 2]))
						dp[i][j] = dp[i][j] || dp[i - 1][j];
				}
			}
		}

		return dp[m][n];
	}

	bool Solution::isMatch(char a, char b) {
		return a == b || b == '.';
	}

	//22. Generate Parentheses 
	vector<string> Solution::generateParenthesis(int n) {
		vector<string> ans;
		generateParenthesis(n, n, ans, "");
		return ans;
	}
	void Solution::generateParenthesis(int left, int right, vector<string>& ans, string s) {
		if (left == 0 && right == 0) {
			ans.push_back(s);
			return;
		}

		if (left < 0 || right <= 0)
			return;

		if (left > 0) {
//			s += '(';
			generateParenthesis(left - 1, right, ans, s + '(');
		}

		if (left < right) {
//			s += ')';
			generateParenthesis(left, right - 1, ans, s + ')');
		}
	}

	//148. Sort List 02/25/2017, 27 minutes
	/* Iterative Merge Sort: time -> O(nlogn), memory->O(1)
       list: a1 a2 a3 a4 a5 a6 a7 a8 a9   -> step = 1 ->
	   ->  (a1 a2)(a3 a4)(a5 a6)(a7 a8)(a9) -> step = 2 ->
	   ->  (a1 a2 a3 a4)(a5 a6 a7 a8)(a9)   -> step = 4 ->
	   ->  (a1 a2 a3 a4 a5 a6 a7 a8)(a9)    -> step = 8 ->
	   ->  (a1 a2 a3 a4 a5 a6 a7 a8 a9)
	   nodes inside ( ) are sorted
	   for each iteration, tail -> last node of sorted sub list
	                       cur  -> first node of to-be-sotred sub list
	   split() function,  split a sub list with len == step, return pointer of next node
	*/
	Solution::ListNode* Solution::sortList148(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode dummy(-1);
		ListNode *left = nullptr, *right = nullptr, *cur = head, *tail = nullptr;
		int len = 1, step = 1;
		while ((cur = cur->next) != nullptr)
			len++;

		dummy.next = head;
		for (; step <= (len + 1) / 2; step *= 2) {
			tail = &dummy;
			cur = dummy.next;
			while (cur != nullptr) {
				left = cur;
				right = split148(left, step);
				cur = split148(right, step);
				tail = merge148(left, right, tail);
			}
		}

		return dummy.next;
	}

	Solution::ListNode* Solution::split148(ListNode *head, int step) {
		for (int i = 1; i < step && head != nullptr; i++)
			head = head->next;

		if (head == nullptr)
			return nullptr;

		ListNode* tmp = head->next;
		head->next = nullptr;
		return tmp;
	}

	Solution::ListNode* Solution::merge148(ListNode *left, ListNode *right, ListNode *tail) {
		while (left != nullptr && right != nullptr) {
			if (left->val <= right->val) {
				tail->next = left;
				tail = tail->next;
				left = left->next;
			}
			else {
				tail->next = right;
				tail = tail->next;
				right = right->next;
			}
		}

		tail->next = left == nullptr ? right : left;
		while (tail->next != nullptr)
			tail = tail->next;

		return tail;
	}

	//503. Next Greater Element II
	vector<int> Solution::nextGreaterElements(vector<int>& nums) {
		int n = nums.size();
		vector<int> ans(n, -1);
		stack<int> s;
		for (int i = 0; i < 2 * n; i++) {
			int tmp = nums[i % n];
			while (!s.empty() && nums[s.top()] < tmp) {
				ans[s.top()] = tmp;
				s.pop();
			}
			if (i < n)
				s.push(i);
			else if (s.empty())
				break;
		}

		return ans;
	}

	//496. Next Greater Element I 
	vector<int> Solution::nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
		map<int, int> m;
		vector<int> ans;
		stack<int> s;
		int n = nums.size();

		for (auto n : nums) {
			while (!s.empty() && s.top() < n) {
				m[s.top()] = n;
				s.pop();
			}

			s.push(n);
		}

		for (auto n : findNums) {
			int tmp = m.find(n) == m.end() ? -1 : m[n];
			ans.push_back(tmp);
		}

		return ans;
	}

	//214. Shortest Palindrome
	string Solution::shortestPalindrome(string s) {
		int len = s.length();
		if (len < 2)
			return s;
		// calculate the length of the longest palindromic prefix substring.
		int longest = 1, start, end;
		for (int begin = 0; begin <= len / 2;) {
			start = end = begin;
			while (end < len - 1 && s[end + 1] == s[end])
				++end;
			begin = end + 1;
			while (end < len - 1 && start > 0 && s[end + 1] == s[start - 1]) {
				++end;
				--start;
			}
			// start == 0 means the palindromic substring is also prefix string.
			if (start == 0 && longest < end - start + 1)
				longest = end - start + 1;
		}
		// reverse the remaining substring and adding it in front of s.
		std::string remaining = s.substr(longest, len - longest);
		std::reverse(remaining.begin(), remaining.end());
		return remaining + s;

	}

	//131. Palindrome Partitioning
	void Solution::test131() {
		string s = "abbab";
		partition131(s);
	}
	vector<vector<string>> Solution::partition131(string s) {
		vector<vector<string>> ans;
		if (s.empty())
			return ans;

		vector<vector<bool>> palindrome(s.size(), vector<bool>(s.size(), false));
		vector<string> path;

		for (int i = 0; i < (int)s.size(); i++) {
			for (int j = i; j >= 0; j--) {
				if (s[i] == s[j] && (i - j < 2 || palindrome[j + 1][i - 1]))
					palindrome[j][i] = true;
			}
		}
		dfs131(0, s, path, ans, palindrome);
		return ans;

/*
		vector<vector<string>> ans;
		if (s.empty())
			return ans;
		vector<string> path;
		dfs131(0, s, path, ans);
		return ans;
*/
	}

	void Solution::dfs131(int start, string s, vector<string> &path, vector<vector<string>> &ans, vector<vector<bool>> &palindrome) {
		if (start == s.size()) {
			ans.push_back(path);
			return;
		}

		for (int end = start; end < (int)s.size(); end++) {
			if (palindrome[start][end]) {
				path.push_back(s.substr(start, end - start + 1));
				dfs131(end + 1, s, path, ans, palindrome);
				path.pop_back();
			}
		}
	}

	void Solution::dfs131(int start, string s, vector<string> &path, vector<vector<string>> &ans) {
		if (start == s.size()) {
			ans.push_back(path);
			return;
		}

		for (int end = start; end < (int)s.size(); end++) {
			if (isPalin131(s, start, end)) {
				path.push_back(s.substr(start, end - start + 1));
				dfs131(end + 1, s, path, ans);
				path.pop_back();
			}
		}
	}

	bool Solution::isPalin131(string s, int start, int end) {
		while (start <= end) {
			if (s[start++] != s[end--])
				return false;
		}

		return true;
	}

	//77. Combinations
	vector<vector<int>> Solution::combine77(int n, int k) {
		vector<vector<int>> ans;
		if (k == 0)
			return ans;

		vector<int> path;
		int beg = 1;
		dfs77(k, beg, n, path, ans);
		return ans;
	}
	void Solution::dfs77(int k, int beg, int n, vector<int> &path, vector<vector<int>> &ans) {
		if (k == 0) {
			ans.push_back(path);
			return;
		}

		for (int start = beg; start <= n; start++) {
			path.push_back(start);
			dfs77(k - 1, start + 1, n, path, ans);
			path.pop_back();
		}
	}

	//90. Subsets II
	/*
	The characteristics of C++ reference is an outstanding tool for backtracking algorithm!
	let us use [1,2,3,4] as an example to explain my solution:
	subsets([1,2,3,4]) = []
	// push(1)
	[1, subsets([2,3,4])] // if push N times in subsets([2,3,4]), the pop times is also N, so vec is also [1] after backtrack.
	// pop(), push(2)
	[2, subsets([3,4])]
	// pop(), push(3)
	[3, subsets([4])]
	// pop(), push(4)
	[4, subsets([])]
	// pop()
	// 
	*/
	vector<vector<int>> Solution::subsetsWithDup(vector<int>& nums) {
		/*
		vector<vector<int>> ans;
		ans.push_back(vector<int>());
		if(nums.empty())
		return ans;

		sort(nums.begin(), nums.end());
		unordered_map<int,int> hashmap;

		for(auto n : nums) {
		int end = hashmap[n];
		hashmap[n] = ans.size();
		for(int j = ans.size() - 1; j >= end; j--) {
		ans.push_back(ans[j]);
		ans.back().push_back(n);
		}
		}
		return ans;
		*/
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		vector<int> path;
		dfs90(0, nums, path, ans);
		return ans;
	}
	void Solution::dfs90(int begin, vector<int> &nums, vector<int> path, vector<vector<int>> &ans) {
		ans.push_back(path);

		for (int i = begin; i < (int)nums.size(); i++) {
			if (i == begin || nums[i] != nums[i - 1]) {
				path.push_back(nums[i]);
				dfs90(i + 1, nums, path, ans);
				path.pop_back();
			}
		}
	}

	//51. N-Queens
	vector<vector<string>> Solution::solveNQueens(int n) {
		vector<vector<string>> ans;
		if (n < 1)
			return ans;
		vector<string> board(n, string(n, '.'));

		Queens(board, 0, ans);
		return ans;
	}

	bool Solution::Queens(vector<string> &board, int col, vector<vector<string>> &ans) {
		if (col >= (int)board.size()) {
			ans.push_back(board);
			return true;
		}
		for (int i = 0; i < (int)board.size(); i++) {
			if (isSafe51(board, i, col)) {
				board[i][col] = 'Q';
				Queens(board, col + 1, ans);
				board[i][col] = '.';
			}
		}

		return false;
	}

	bool Solution::isSafe51(vector<string> &board, int row, int col) {
		for (int i = 0; i < col; i++)
			if (board[row][i] == 'Q')
				return false;

		for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
			if (board[i][j] == 'Q')
				return false;

		for (int i = row, j = col; i < (int)board.size() && j >= 0; i++, j--)
			if (board[i][j] == 'Q')
				return false;

		return true;
	}

	// 52. N-Queens II
	int Solution::totalNQueens52(int n) {
		int ans = 0;
		if (n < 1)
			return ans;

		vector<vector<bool>> board(n, vector<bool>(n, false));
		Queens52(board, 0, ans);

		return ans;
	}

	bool Solution::Queens52(vector<vector<bool>> &board, int col, int &ans) {
		int n = board.size();
		if (col >= n) {
			ans++;
			return true;
		}

		for (int i = 0; i < n; i++) {
			if (isSafe52(board, i, col)) {
				board[i][col] = true;
				Queens52(board, col + 1, ans);
				board[i][col] = false;
			}
		}

		return false;
	}

	bool Solution::isSafe52(vector<vector<bool>> &board, int row, int col) {
		for (int i = 0; i < col; i++)
			if (board[row][i])
				return false;
		for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
			if (board[i][j])
				return false;
		for (int i = row, j = col; i < (int)board.size() && j >= 0; i++, j--)
			if (board[i][j])
				return false;

		return true;
	}

	/*
	(1) put the first index pair into the min_heap
	(2) assuming the index pair on the top of the min_heap is (i, j), then next smallest pair should be either (i, j+1) or (i+1, 0)
	*/
	//373. Find K Pairs with Smallest Sums
	vector<pair<int, int>> Solution::kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<pair<int, int>> ans;
		if (nums1.empty() || nums2.empty())
			return ans;

		int index = 1, m = nums1.size(), n = nums2.size();
		auto cmp = [&](pair<int, int> a, pair<int, int> b) {return (nums1[a.first] + nums2[a.second]) > (nums1[b.first] + nums2[b.second]); };
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> heap(cmp);
		heap.push(pair<int, int>(0, 0));
		while (k-- > 0 && !heap.empty()) {
			int i = heap.top().first, j = heap.top().second;
			heap.pop();
			ans.push_back(pair<int, int>(nums1[i], nums2[j]));
			if (j + 1 < n)
				heap.push(pair<int, int>(i, j + 1));
			if (i + 1 < m && i + 1 == index) {
				index++;
				heap.push(pair<int, int>(i + 1, 0));
			}

		}

		return ans;
		/*
		vector<pair<int,int>> ans;
		auto cmp = [](pair<int,int> a, pair<int, int> b) {return (a.first + a.second) < (b.first + b.second);};
		priority_queue<pair<int,int>, vector<pair<int,int>>,decltype(cmp)> heap(cmp);
		int m = nums1.size(), n = nums2.size();

		for(int i = 0; i < m && i < k; i++)
		for(int j = 0; j < n && j < k; j++) {
		heap.push(pair<int, int>(nums1[i], nums2[j]));
		if(heap.size() > k)
		heap.pop();
		}

		while(!heap.empty()) {
		ans.push_back(heap.top());
		heap.pop();
		}

		return ans;
		*/
	}

	//392. Is Subsequence
	bool Solution::isSubsequence(string s, string t) {
		if (s.empty())
			return true;
		if (t.empty())
			return false;

		int i = 0;
		for (int j = 0; i < (int)s.size() && j < (int)t.size(); j++) {
			if (s[i] == t[j])
				i++;
		}

		return i == s.size();
	}

	//252. Meeting Rooms
	bool Solution::canAttendMeetings(vector<Interval>& intervals) {
		if (intervals.empty())
			return true;

		auto cmp = [](Interval a, Interval b) {return a.start < b.start; };
		sort(intervals.begin(), intervals.end(), cmp);
		for (int i = 0; i < (int)intervals.size() - 1; i++)
			if (intervals[i].end > intervals[i + 1].start)
				return false;

		return true;
	}

	//253. Meeting Rooms II
	int Solution::minMeetingRooms(vector<Interval>& intervals) {
		if (intervals.empty())
			return 0;
		int ans = 1;
		auto cmp = [](int a, int b) {return a > b; };
		sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {return a.start < b.start; });
		priority_queue<int, vector<int>, decltype(cmp)> heap(cmp);
		heap.push(intervals[0].end);
		for (int i = 1; i < (int)intervals.size(); i++) {
			if (heap.top() <= intervals[i].start) {
				heap.pop();
				heap.push(intervals[i].end);
			}
			else {
				heap.push(intervals[i].end);
				ans++;
			}
		}

		return ans;
	}

	//80. Remove Duplicates from Sorted Array II
	int Solution::removeDuplicatesII(vector<int>& nums) {
		int index = 0;

		for (auto n : nums) {
			if (index < 2 || n > nums[index - 2])
				nums[index++] = n;
		}

		return index;
	}

	//82. Remove Duplicates from Sorted List II
	Solution::ListNode* Solution::deleteDuplicatesII(ListNode* head) {
		ListNode dummy(-1), *pre = &dummy, *cur = head;
		pre->next = cur;
		while (cur != nullptr) {
			while (cur->next != nullptr && cur->val == cur->next->val)
				cur = cur->next;
			if (pre->next == cur)
				pre = cur;
			else
				pre->next = cur->next;
			cur = cur->next;
		}

		return dummy.next;
	}

	//402. Remove K Digits 
	string Solution::removeKdigits(string num, int k) {
		string res = "";
		int pos = 0, count = k;

		for (auto c : num) {
			while (!res.empty() && res.back() > c && count-- > 0)
				res.pop_back();
			res.push_back(c);
		}

		while (res[pos] == '0')
			pos++;
		res = res.substr(pos, num.size() - k - pos);

		return res.empty() ? "0" : res;
	}

	//143. Reorder List
	void Solution::reorderList(ListNode* head) {
		if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
			return;
		ListNode *p1 = head, *p2 = head;
		while (p2->next != nullptr && p2->next->next != nullptr) {
			p1 = p1->next;
			p2 = p2->next->next;
		}

		p2 = p1->next;
		p1->next = nullptr;

		p2 = reverseList(p2);
		p1 = head;

		while (p1 != nullptr && p2 != nullptr) {
			ListNode* tmp = p1->next;
			p1->next = p2;
			p2 = p2->next;
			p1->next->next = tmp;
			p1 = tmp;
		}

		return;
	}

	Solution::ListNode* Solution::reverseList(ListNode *head) {
		ListNode *pre = nullptr;
		while (head != nullptr) {
			ListNode *tmp = head->next;
			head->next = pre;
			pre = head;
			head = tmp;
		}

		return pre;
	}

	//39. Combination Sum
	vector<vector<int>> Solution::combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> res;
		vector<int> path;
		sort(candidates.begin(), candidates.end());
		dfs39(candidates, target, 0, path, res);
		return res;
	}
	void Solution::dfs39(vector<int>& candidates, int target, int index, vector<int> path, vector<vector<int>> &res) {
		if (target == 0) {
			res.push_back(path);
			return;
		}

		for (int j = index; j < (int)candidates.size() && candidates[j] <= target; j++) {
			path.push_back(candidates[j]);
			dfs39(candidates, target - candidates[j], j, path, res);
			path.pop_back();
		}
	}

	//40. Combination Sum II
	vector<vector<int>> Solution::combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> res;
		vector<int> path;
		sort(candidates.begin(), candidates.end());
		dfs40(candidates, target, path, res, 0);
		return res;
	}
	void Solution::dfs40(vector<int>& candidates, int target, vector<int> path, vector<vector<int>>& res, int index) {
		if (target == 0) {
			res.push_back(path);
			return;
		}
		for (int i = index; i < (int)candidates.size() && candidates[i] <= target; i++) {
			if (i == index || candidates[i] != candidates[i - 1]) {
				path.push_back(candidates[i]);
				dfs40(candidates, target - candidates[i], path, res, i + 1);
				path.pop_back();
			}
		}
	}

	//216. Combination Sum III
	vector<vector<int>> Solution::combinationSum3(int k, int n) {
		vector<vector<int>> res;
		vector<int> path;
		dfs216(k, n, path, res, 1);
		return res;
	}

	void Solution::dfs216(int k, int n, vector<int> path, vector<vector<int>>& res, int index) {
		if (k == 0 && n == 0) {
			res.push_back(path);
			return;
		}
		else if (k == 0)
			return;

		for (int i = index; i < 10 && i <= n; i++) {
			path.push_back(i);
			dfs216(k - 1, n - i, path, res, i + 1);
			path.pop_back();
		}
	}

	//16. 3Sum Closest
	int Solution::threeSumClosest(vector<int>& nums, int target) {
		int size = nums.size();
		if (size < 3)
			return 0;

		sort(nums.begin(), nums.end());
		int closest = nums[0] + nums[1] + nums[2];
		for (int first = 0; first < size - 2; first++) {
			if (first > 0 && nums[first] == nums[first - 1])
				continue;
			int second = first + 1, third = size - 1;
			while (second < third) {
				int sum = nums[first] + nums[second] + nums[third];
				if (sum == target)
					return sum;
				else if (abs(sum - target) < abs(closest - target))
					closest = sum;
				if (sum > target)
					third--;
				else
					second++;
			}
		}

		return closest;
	}

	//29. Divide Two Integers
	/*
	In this problem, we are asked to divide two integers. However, we are not allowed to use division, multiplication and mod operations. So, what else can we use? Yeah, bit manipulations.
	Let's do an example and see how bit manipulations work.
	Suppose we want to divide 15 by 3, so 15 is dividend and 3 is divisor. Well, division simply requires us to find how many times we can subtract the divisor from the the dividend without making the dividend negative.
	Let's get started. We subtract 3 from 15 and we get 12, which is positive. Let's try to subtract more. Well, we shift 3 to the left by 1 bit and we get 6. Subtracting 6 from 15 still gives a positive result. Well, we shift again and get 12. We subtract 12 from 15 and it is still positive. We shift again, obtaining 24 and we know we can at most subtract 12. Well, since 12 is obtained by shifting 3 to left twice, we know it is 4 times of 3. How do we obtain this 4? Well, we start from 1 and shift it to left twice at the same time. We add 4 to an answer (initialized to be 0). In fact, the above process is like 15 = 3 * 4 + 3. We now get part of the quotient (4), with a remainder 3.
	Then we repeat the above process again. We subtract divisor = 3 from the remaining dividend = 3 and obtain 0. We know we are done. No shift happens, so we simply add 1 << 0 to the answer.
	Now we have the full algorithm to perform division.
	According to the problem statement, we need to handle some exceptions, such as overflow.
	Well, two cases may cause overflow:
	divisor = 0;
	dividend = INT_MIN and divisor = -1 (because abs(INT_MIN) = INT_MAX + 1).
	Of course, we also need to take the sign into considerations, which is relatively easy.
	Putting all these together, we have the following code.
	*/
	int Solution::divide(int dividend, int divisor) {
		if (divisor == 0 || (dividend == INT_MIN && divisor == -1))
			return INT_MAX;
		long sign = 0;
		sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
		long long res = 0, dvd = llabs(dividend), dvr = llabs(divisor);
		while (dvd >= dvr) {
			long long tmp = dvr, tmpRes = 1;
			while (dvd >(tmp << 1)) {
				tmp <<= 1;
				tmpRes <<= 1;
			}

			dvd -= tmp;
			res += tmpRes;
		}

		return sign == -1 ? (int)-res : (int)res;
	}

	//31. Next Permutation
	/*
	Well, in fact the problem of next permutation has been studied long ago. From the Wikipedia page, in the 14th century, a man named Narayana Pandita gives the following classic and yet quite simple algorithm (with minor modifications in notations to fit the problem statement):
	Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, the permutation is sorted in descending order, just reverse it to ascending order and we are done. For example, the next permutation of [3, 2, 1] is [1, 2, 3].
	Find the largest index l greater than k such that nums[k] < nums[l].
	Swap the value of nums[k] with that of nums[l].
	Reverse the sequence from nums[k + 1] up to and including the final element nums[nums.size() - 1].

	If you find k,the elements behind it must be in descending order(can be proofed by contradiction easily), similarly, the nums[l] must be the minimal element that bigger than nums[k] behind nums[k] . Since the elements behind k are in descending order,the next Permutation in position k must be nums[l],and the elements behind k are in ascending order after swap the value of nums[k] with that of nums[l].Again,since the elements behind k are in descending order(after swap is also right),so we need to reverse the sequence from nums[k + 1] up to and including the final element nums[nums.size() - 1].
	*/
	void Solution::nextPermutation(vector<int>& nums) {
		// Find from the smallest k such that nums[k - 1] < nums[k].
		int k;
		for (k = nums.size() - 1; k > 0 && nums[k - 1] >= nums[k]; k--);

		// k == 0 means the sequence itself is non-increasing. Reverse it.
		if (k > 0) {
			// Find the index i such that nums[i] > nums[k-1], i in [k, n-1].
			int i;
			for (i = nums.size() - 1; nums[i] <= nums[k - 1]; i--);

			swap(nums[k - 1], nums[i]);
		}
		reverse(nums.begin() + k, nums.end());
	}

	//32. Longest Valid Parentheses
	int Solution::longestValidParentheses(string s) {
		int res = 0, size = s.size();
		// len[i] records the longest valid length at position i
		vector<int> len(size, 0);
		for (int i = 1; i < size; i++) {
			if (s[i] == ')') {
				if (s[i - 1] == '(' || (i - 1 - len[i - 1] >= 0 && s[i - 1 - len[i - 1]] == '(')) {
					len[i] = len[i - 1] + 2 + (i - 2 - len[i - 1] >= 0 ? len[i - 2 - len[i - 1]] : 0);
					res = max(res, len[i]);
				}
			}
			// else if s[i] == '(', len[i] = 0
		}

		return res;
	}

	//41. First Missing Positive 
	/*
	Put each number in its right place.
	For example:
	When we find 5, then swap it with nums[4].
	At last, the first place where its number is not right, return the place + 1.
	*/
	int Solution::firstMissingPositive(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n;) {
			if (nums[i] > 0 && nums[i] < n && nums[nums[i] - 1] != nums[i])
				swap(nums[i], nums[nums[i] - 1]);
			else
				i++;
		}

		for (int i = 0; i < n; i++) {
			if (nums[i] != i + 1)
				return i + 1;
		}

		return n + 1;
	}

	// test of factorial, 03/10/2017
	vector<unsigned int> Solution::factorial(unsigned int n) {
		vector<unsigned int> nums(100, 0);
		unsigned int carry = 0, digit = 1, temp = 0;
		nums[0] = 1;
		for (unsigned int i = 2; i <= n; ++i)
		{
			for (unsigned int j = 0; j < digit; j++)
			{
				temp = nums[j] * i + carry;
				nums[j] = temp % 10;
				carry = temp / 10;
			}
			while (carry)
			{
				digit++;
				if (digit >= nums.size())
					nums.resize(100 + digit);
				nums[digit - 1] = carry % 10;
				carry = carry / 10;
			}
		}

		return nums;
	}

	// calling function like this: factorial(10, 1);
	int Solution::factorial(unsigned int n, unsigned int res) {
		if (n == 0)
			return 0;
		else if (n == 1)
			return res;

		return factorial(n - 1, n * res);
	}

	//43. Multiply Strings 
	string Solution::multiply(string num1, string num2) {
		int m = num1.size(), n = num2.size(), pos = 0;
		if (m == 0 || n == 0)
			return "";
		if ((m == 1 && num1[0] == '0') || (n == 1 && num2[0] == '0'))
			return "0";

		string res(m + n, '0');

		for (int i = m - 1; i >= 0; i--) {
			int carry = 0;
			for (int j = n - 1; j >= 0; j--) {
				pos = i + j + 1;
				int tmp = (num1[i] - '0') * (num2[j] - '0') + carry + (res[pos] - '0');
				res[pos] = char(tmp % 10 + '0');
				carry = tmp / 10;
			}

			if (carry)
				res[--pos] = char(carry % 10 + '0');
		}

		return res.substr(pos, m + n - pos);
	}

	//45. Jump Game II
	int Solution::jumpII(vector<int>& nums) {
		int step_count = 0;
		int last_jump_max = 0;
		int current_jump_max = 0;
		for (int i = 0; i<(int)nums.size() - 1; i++) {
			current_jump_max = max(current_jump_max, i + nums[i]);
			if (i == last_jump_max) {
				step_count++;
				last_jump_max = current_jump_max;
			}
		}
		return step_count;
/*
		if (nums.empty())
			return 0;
		int size = nums.size(), distance = nums[0];
		vector<int> dp(size, size - 1);
		dp[0] = 0;
		for (int i = 0; i < size; i++) {
			int tmp = distance;
			for (int j = i; j <= tmp && j < size; j++) {
				dp[j] = min(dp[i] + 1, dp[j]);
				distance = max(distance, nums[j] + j);
			}
		}

		return dp[size - 1];
*/
	}

	// Endianness Test
	bool Solution::EndiannessTest() {
		const int littleEndian = 0, bigEndian = 1;
		int endian = 0x201;
		char *test = (char *)&endian;
		if (test[0] == 1)
			return littleEndian;
		else
			return bigEndian;
	}

	// test of volatile
	void Solution::TestVolatileInt() {
		uint8_t * p1 = (uint8_t *)&nonVolatileInt;
		char* p2 = (char *)&volatileInt;

		nonVolatileInt = 1;
		volatileInt = 1;
		for (int i = 0; i < 10; i++);

		return;
	}

	// test of my strcpy
	void Solution::MyStrCpy() {
		int i = 0;
//		int test[100];
//		char testchar[200];

		char* strDest = (char *)malloc(20);
		char* strTmp = strDest;
		for (int i = 0; i < 19; i++)
			*strTmp++ = char ('A' + i);
		*strTmp = '\0';
		strTmp = strDest;
		char* strSrc = strDest + 5;
		while ((*strDest++ = *strSrc++) != '\0')
			i++;

		free(strTmp);

		return;
	}

	//test of tailrecursive: fibonacci sequence
	// calling for the function:: int res = fibonacci(1, 0, 10);
	int Solution::fibonacci(int a, int b, int n) {
		if (n == 0)
			return a;

		return fibonacci(a + b, a, n - 1);
	}

	//50. Pow(x, n) 
	/*
	N = 9 = 2^3 + 2^0 = 1001 in binary. Then:
	x^9 = x^(2^3) * x^(2^0)
	We can see that every time we encounter a 1 in the binary representation of N, we need to multiply the answer with x^(2^i) where i is the ith bit of the exponent. Thus, we can keep a running total of repeatedly squaring x - (x, x^2, x^4, x^8, etc) and multiply it by the answer when we see a 1.
	To handle the case where N=INTEGER_MIN we use a long (64-bit) variable.
	*/
	double Solution::myPow(double x, int n) {
		unsigned int un = abs(n);
		double res = 1;
		while (un > 0) {
			if (un & 1)
				res *= x;
			un >>= 1;
			x *= x;
		}
		return (n < 0) ? 1 / res : res;
		/*
		unsigned int un = abs(n);
		return (n < 0) ? 1 / myPow(x, un) : myPow(x, un);
		*/
	}

	double Solution::myPow(double x, unsigned int n) {
		if (n == 0)
			return 1;
		else if (n & 1)
			return x * myPow(x, n - 1);
		else {
			double tmp = myPow(x, n / 2);
			return tmp * tmp;
		}
	}

	//69. Sqrt(x) 
	int Solution::mySqrt(int x) {
		long r = x;
		while (r * r > x)
			r = (r + (long long)x / r) / 2;

		return (int)r;
		/*
		if(x < 1)
		return 0;

		int left = 1, right = x / 2;
		while(left < right) {
		int mid = left + (right - left) / 2;
		if(mid > x / mid)
		right = mid;
		else if(mid < x / mid)
		left = mid + 1;
		else
		return mid;
		}
		return (left > x / left) ? left - 1 : left;
		*/
	}

	//74. Search a 2D Matrix
	bool Solution::searchMatrixI(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty())
			return false;
		long long m = matrix.size(), n = matrix[0].size(), left = 0, right = m * n - 1;
		while (left <= right) {
			long long mid = left + (right - left) / 2;
			int i = (int)(mid / n), j = (int)(mid % n);
			if (matrix[i][j] == target)
				return true;
			else if (matrix[i][j] > target)
				right = mid - 1;
			else
				left = mid + 1;
		}

		int i = (int)(left / n), j = (int)(left % n);
		return left < m * n && matrix[i][j] == target;
	}

	// 81. Search in Rotated Sorted Array II
	/*
	(1) nums[mid] == nums[right] -> right-- eg. 1 1 3 1 1 1 1 1
	(2) nums[mid] > nums[right] -> orignal head in right, eg. 1 1 3 4 1 1 1 2. This means left part is a increasing sequence
	(3) nums[mid] < nums[right] -> orignal head in left or mid , eg. 1 1 3 1 1 1 1 2. This means right part is a increasing sequence
	*/
	bool Solution::search81(vector<int>& nums, int target) {
		if (nums.empty())
			return false;

		int left = 0, right = nums.size() - 1;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == target)
				return true;

			if (nums[mid] == nums[right])
				right--;
			else if (nums[mid] > nums[right]) {
				if (nums[left] <= target && nums[mid] > target)
					right = mid;
				else
					left = mid + 1;
			}
			else {
				if (nums[mid] < target && nums[right] >= target)
					left = mid + 1;
				else
					right = mid;
			}
		}

		return nums[left] == target;
	}

	//60. Permutation Sequence 
	string Solution::getPermutation60(int n, int k) {
		string seq = "";
		char last = '0' + n;
		for (char i = '1'; i <= last; i++)
			seq.push_back(i);

		vector<string> res;
		getPermutation60(seq, k, res, 0);
		return res.back();
	}
	void Solution::getPermutation60(string seq, int k, vector<string>& res, int index) {
		if (res.size() == k) {
			return;
		}
		if (index == seq.size()) {
			res.push_back(seq);
			return;
		}

		for (int i = index; i < (int)seq.size(); i++) {
			swap(seq[index], seq[i]);
			getPermutation60(seq, k, res, i + 1);
			swap(seq[index], seq[i]);
		}

		return;
	}

	/*
	start by noting that 1..n is the in-order traversal for any BST with nodes 1 to n. 
	So if I pick i-th node as my root, the left subtree will contain elements 1 to (i-1), 
	and the right subtree will contain elements (i+1) to n. 
	I use recursive calls to get back all possible trees for left and right subtrees 
	and combine them in all possible ways with the root.
	*/
	//128. Longest Consecutive Sequence 
	int Solution::longestConsecutive(vector<int>& nums) {
		if (nums.empty())
			return 0;

		unordered_set<int> numSets(nums.begin(), nums.end());
		int res = 1;

		for (auto n : nums) {
			if (numSets.find(n - 1) == numSets.end()) {
				int y = n + 1;
				while (numSets.find(y) != numSets.end())
					y++;

				res = max(res, y - n);
			}
		}

		return res;
	};

	//95. Unique Binary Search Trees II 
	vector<Solution::TreeNode*> Solution::generateTrees(int n) {
		if (n <= 0)
			return vector<TreeNode*>();

		return generateTrees(1, n);
	}

	vector<Solution::TreeNode*> Solution::generateTrees(int start, int end) {
		vector<TreeNode*> res;
		if (start > end) {
			res.push_back(nullptr);
			return res;
		}
		else if (start == end) {
			res.push_back(new TreeNode(start));
			return res;
		}
		else {
			for (int i = start; i <= end; i++) {
				vector<TreeNode*> left, right;
				left = generateTrees(start, i - 1);
				right = generateTrees(i + 1, end);
				for (auto leftSubTree : left) {
					for (auto rightSubTree : right) {
						TreeNode* root = new TreeNode(i);
						root->left = leftSubTree;
						root->right = rightSubTree;
						res.push_back(root);
					}
				}
			}
		}

		return res;
	}

	//63. Unique Paths II
	int Solution::uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid.empty() || obstacleGrid[0].empty())
			return 0;

		int m = obstacleGrid.size(), n = obstacleGrid[0].size();
		vector<vector<int>> dp(m, vector<int>(n, 0));
		dp[0][0] = (obstacleGrid[0][0] == 1) ? 0 : 1;

		for (int i = 1; i < m; i++)
			if (obstacleGrid[i][0] == 0)
				dp[i][0] = dp[i - 1][0];
		for (int j = 1; j < n; j++)
			if (obstacleGrid[0][j] == 0)
				dp[0][j] = dp[0][j - 1];

		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (obstacleGrid[i][j] == 0)
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}

		return dp[m - 1][n - 1];
	}

	//133. Clone Graph
	Solution::UndirectedGraphNode* Solution::cloneGraph(UndirectedGraphNode *node) {
		if (node == nullptr)
			return nullptr;
		if (hashmap133.find(node) == hashmap133.end()) {
			hashmap133[node] = new UndirectedGraphNode(node->label);
			for (auto p : node->neighbors)
				hashmap133[node]->neighbors.push_back(cloneGraph(p));
		}
		return hashmap133[node];
	}

	//93. Restore IP Addresses
	vector<string> Solution::restoreIpAddresses(string s) {
		vector<string> res;
		int len = s.size();
		for (int i = 1; i < 4 && i < len - 2; i++)
			for (int j = i + 1; j - i < 4 && j < len - 1; j++)
				for (int k = j + 1; k - j < 4 && k < len; k++) {
					string s1 = s.substr(0, i), s2 = s.substr(i, j - i), s3 = s.substr(j, k - j), s4 = s.substr(k, len - k);
					if (isValid93(s1) && isValid93(s2) && isValid93(s3) && isValid93(s4))
						res.push_back(s1 + "." + s2 + "." + s3 + "." + s4);
				}

		return res;
	}

	bool Solution::isValid93(string s) {
		if ((s.front() == '0' && s.size() > 1) || (s.size() <= 3 && stoi(s) > 255) || s.empty() || s.size() > 3)
			return false;
		return true;
	}

	//134. Gas Station
	int Solution::canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		if (gas.empty() || cost.empty() || gas.size() > cost.size())
			return 0;

		int start = 0, gap = 0, tank = 0, n = gas.size();
		for (int i = 0; i < n; i++) {
			tank += gas[i] - cost[i];
			if (tank < 0) {
				start = i + 1;
				gap += tank;
				tank = 0;
			}
		}

		return (gap + tank) < 0 ? -1 : start % n;
	}

	//99. Recover Binary Search Tree 
	//morris traversal
	void Solution::recoverTree(TreeNode* root) {
		TreeNode *cur = root, *InorderPre = nullptr, *predecessor = nullptr, *target1 = nullptr, *target2 = nullptr;

		while (cur != nullptr) {
			if (cur->left == nullptr) {
				FindTarget(InorderPre, cur, target1, target2);
				InorderPre = cur;
				cur = cur->right;
			}
			else {
				predecessor = cur->left;
				while (predecessor->right != nullptr && predecessor->right != cur)
					predecessor = predecessor->right;
				if (predecessor->right == nullptr) {
					predecessor->right = cur;
					cur = cur->left;
				}
				else {
                    FindTarget(InorderPre, cur, target1, target2);
					InorderPre = cur;
					predecessor->right = nullptr;
					cur = cur->right;
				}
			}
		}

		if(target1 != nullptr && target2 != nullptr) {
			int tmp = target1->val;
			target1->val = target2->val;
			target2->val = tmp;
		}

		return;
	}

	void Solution::FindTarget(TreeNode *pre, TreeNode *cur, TreeNode *&target1, TreeNode *&target2) {
		if (pre == nullptr)
			return;
		if (pre->val > cur->val) {
			if (target1 == nullptr)
				target1 = pre;
			target2 = cur;
		}
	}

	//86. Partition List
	Solution::ListNode* Solution::partition(ListNode* head, int x) {
		ListNode node1(-1), node2(-1), *p1 = &node1, *p2 = &node2;
		while (head != nullptr) {
			if (head->val < x) {
				p1->next = head;
				p1 = head;
			}
			else {
				p2->next = head;
				p2 = head;
			}
			head = head->next;
		}

		p1->next = node2.next;
		p2->next = nullptr;

		return node1.next;
	}

	//129. Sum Root to Leaf Numbers
	int Solution::sumNumbers(TreeNode* root) {
		int result = 0;
		sumNumbers(root, 0, result);

		return result;
	}

	void Solution::sumNumbers(TreeNode* root, int path, int &result) {
		if (root == nullptr) {
			return;
		}
		else if (root->left == nullptr && root->right == nullptr) {
			path = path * 10 + root->val;
			result += path;
			return;
		}
		else {
			path = path * 10 + root->val;
			sumNumbers(root->left, path, result);
			sumNumbers(root->right, path, result);
		}
	}

	//120. Triangle
	/*
	The triangle has a tree-like structure, which would lead people to think about traversal algorithms such as DFS. However, if you look closely, you would notice that the adjacent nodes always share a 'branch'. In other word, there are overlapping subproblems. Also, suppose x and y are 'children' of k. Once minimum paths from x and y to the bottom are known, the minimum path starting from k can be decided in O(1), that is optimal substructure. Therefore, dynamic programming would be the best solution to this problem in terms of time complexity.
	What I like about this problem even more is that the difference between 'top-down' and 'bottom-up' DP can be 'literally' pictured in the input triangle. For 'top-down' DP, starting from the node on the very top, we recursively find the minimum path sum of each node. When a path sum is calculated, we store it in an array (memoization); the next time we need to calculate the path sum of the same node, just retrieve it from the array. However, you will need a cache that is at least the same size as the input triangle itself to store the pathsum, which takes O(N^2) space. With some clever thinking, it might be possible to release some of the memory that will never be used after a particular point, but the order of the nodes being processed is not straightforwardly seen in a recursive solution, so deciding which part of the cache to discard can be a hard job.
	'Bottom-up' DP, on the other hand, is very straightforward: we start from the nodes on the bottom row; the min pathsums for these nodes are the values of the nodes themselves. From there, the min pathsum at the ith node on the kth row would be the lesser of the pathsums of its two children plus the value of itself, i.e.:
	minpath[k][i] = min( minpath[k+1][i], minpath[k+1][i+1]) + triangle[k][i];
	Or even better, since the row minpath[k+1] would be useless after minpath[k] is computed, we can simply set minpath as a 1D array, and iteratively update itself:
	For the kth level:
	minpath[i] = min( minpath[i], minpath[i+1]) + triangle[k][i];
	*/
	int Solution::minimumTotal(vector<vector<int>>& triangle) {
		if (triangle.empty() || triangle[0].empty())
			return 0;

		vector<int> minpath(triangle.back());
		int layers = triangle.size();
		for (int i = layers - 2; i >= 0; i--) {
			for (int j = 0; j <= i; j++)
				minpath[j] = min(minpath[j], minpath[j + 1]) + triangle[i][j];
		}

		return minpath[0];
	}

	//130. Surrounded Regions
	void Solution::Test130() {
		vector<vector<char>> test130(200, vector<char>(200, 'O'));
		for (int i = 1; i <= 198; i++) {
			test130[i][1] = 'X';
			test130[i][198] = 'X';
			test130[1][i] = 'X';
			test130[198][i] = 'X';
		}

		solve(test130);
	}
	void Solution::solve(vector<vector<char>>& board) {
		if (board.empty() || board[0].empty())
			return;

		SetBoarder(board, 'O', 'Y');
		int m = board.size(), n = board[0].size();
		for (int i = 1; i < m - 1; i++) {
			for (int j = 1; j < n - 1; j++) {
				if (board[i][j] == 'O')
					SetDFS(board, i, j, 'O', 'X');
			}
		}

		SetBoarder(board, 'Y', 'O');
	}

	void Solution::SetDFS(vector<vector<char>> &board, int i, int j, char src, char dest) {
		if (board[i][j] == dest)
			return;
		if (board[i][j] == src) {
			board[i][j] = dest;
			if (i > 0)
				SetDFS(board, i - 1, j, src, dest);
			if (i + 1 < (int)board.size())
				SetDFS(board, i + 1, j, src, dest);
			if (j > 0)
				SetDFS(board, i, j - 1, src, dest);
			if (j + 1 < (int)board[0].size())
				SetDFS(board, i, j + 1, src, dest);
		}
	}

	void Solution::SetBoarder(vector<vector<char>> &board, char src, char dest) {
		int m = board.size(), n = board[0].size();
		for (int i = 0; i < m; i++) {
			if (board[i][0] == src)
				SetDFS(board, i, 0, src, dest);
			if (board[i][n - 1] == src)
				SetDFS(board, i, n - 1, src, dest);
		}
		for (int j = 0; j < n; j++) {
			if (board[0][j] == src)
				SetDFS(board, 0, j, src, dest);
			if (board[m - 1][j] == src)
				SetDFS(board, m - 1, j, src, dest);
		}
	}

	//37. Sudoku Solver
	void Solution::test37() {
		vector<vector<char>> test = {
		{ '.', '.', '9', '7', '4', '8', '.', '.', '.' },
		{ '7', '.', '.', '.', '.', '.', '.', '.', '.' },
		{ '.', '2', '.', '1', '.', '9', '.', '.', '.' },
		{ '.', '.', '7', '.', '.', '.', '2', '4', '.' },
		{ '.', '6', '4', '.', '1', '.', '5', '9', '.' },
		{ '.', '9', '8', '.', '.', '.', '3', '.', '.' },
		{ '.', '.', '.', '8', '.', '3', '.', '2', '.' },
		{ '.', '.', '.', '.', '.', '.', '.', '.', '6' },
		{ '.', '.', '.', '2', '7', '5', '9', '.', '.' }
		};


		solveSudoku(test);
		int i = 0;
		i++;
	}

	void Solution::solveSudoku(vector<vector<char>>& board) {
		vector<pair<int, int>> pos;
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				if (board[i][j] == '.')
					pos.push_back(pair<int, int>(i, j));

		solveSudoku(board, pos, 0);
		return;
	}

	bool Solution::solveSudoku(vector<vector<char>>& board, vector<pair<int, int>> &pos, int cur) {
		if (cur >= (int)pos.size())
			return true;

		int row = pos[cur].first, col = pos[cur].second;

		for (char c = '1'; c <= '9'; c++) {
			if (isValid37(board, row, col, c)) {
				board[row][col] = c;
				if (solveSudoku(board, pos, cur + 1))
					return true;
				board[row][col] = '.';
			}
		}

		return false;
	}

	bool Solution::isValid37(vector<vector<char>> &board, int row, int col, char c) {
		int subrow = (row / 3) * 3, subcol = (col / 3) * 3;
		for (int i = 0; i < 9; i++)
			if (board[i][col] == c || board[row][i] == c || board[subrow + i / 3][subcol + i % 3] == c)
				return false;

		return true;
	}

/*
	void Solution::solveSudoku(vector<vector<char>>& board) {
		solveSudoku(board, 0, 0);
		return;
	}

	bool Solution::solveSudoku(vector<vector<char>>& board, int row, int col) {
		for (int i = row; i < 9; i++, col = 0) {
			for (int j = col; j < 9; j++) {
				if (board[i][j] == '.') {
					for (char k = '1'; k <= '9'; k++) {
						if (isValid37(board, i, j, k)) {
							board[i][j] = k;
							if (solveSudoku(board, i, j + 1))
								return true;
							board[i][j] = '.';
						}
					}
					return false;
				}
			}
		}

		return true;
	}

	bool Solution::isValid37(vector<vector<char>> &board, int row, int col, char c) {
		int subrow = (row / 3) * 3, subcol = (col / 3) * 3;
		for (int i = 0; i < 9; i++)
			if (board[i][col] == c || board[row][i] == c || board[subrow + i / 3][subcol + i % 3] == c)
				return false;

		return true;
	}
*/
	//Finding Profession geeks
	char Solution::find_geeks1(int level, int pos) {
		if (level == 1) {
			return 'e';
		}

		char par = find_geeks1(level - 1, (pos + 1) / 2);
		if (par == 'e') {
			return (pos % 2 == 1) ? 'e' : 'd';
		}
		else {
			return (pos % 2 == 1) ? 'd' : 'e';
		}
	}

	//geeks : Dynamic Programming | Set 7 (Coin Change)
	int Solution::count(int S[], int m, int n)
	{
		// table[i] will be storing the number of solutions for
		// value i. We need n+1 rows as the table is consturcted
		// in bottom up manner using the base case (n = 0)
		vector<int> table(n+1, 0);

		// Base case (If given value is 0)
		table[0] = 1;

		// Pick all coins one by one and update the table[] values
		// after the index greater than or equal to the value of the
		// picked coin
		for (int i = 0; i<m; i++)
			for (int j = S[i]; j <= n; j++)
				table[j] += table[j - S[i]];

		return table[n];

/*
		int i, j, x, y;

		// We need n+1 rows as the table is consturcted in bottom up manner using 
		// the base case 0 value case (n = 0)
		vector<vector<int>> table(n+1, vector<int>(m, 0));

		// Fill the enteries for 0 value case (n = 0)
		for (i = 0; i<m; i++)
			table[0][i] = 1;

		// Fill rest of the table enteries in bottom up manner  
		for (i = 1; i < n + 1; i++)
		{
			for (j = 0; j < m; j++)
			{
				// Count of solutions including S[j]
				x = (i - S[j] >= 0) ? table[i - S[j]][j] : 0;

				// Count of solutions excluding S[j]
				y = (j >= 1) ? table[i][j - 1] : 0;

				// total count
				table[i][j] = x + y;
			}
		}
		return table[n][m - 1];
*/
	}

	//264. Ugly Number II
	int Solution::nthUglyNumber(int n) {
		if (n < 1)
			return -1;

		vector<int> uglyNumber(n, 1);
		int i2 = 0, i3 = 0, i5 = 0, next2 = 2, next3 = 3, next5 = 5, nextUglyNumber = 1;
		for (int i = 1; i < n; i++) {
			nextUglyNumber = min(next2, min(next3, next5));
			uglyNumber[i] = nextUglyNumber;
			if (nextUglyNumber == next2) {
				i2++;
				next2 = uglyNumber[i2] * 2;
			}
			if (nextUglyNumber == next3) {
				i3++;
				next3 = uglyNumber[i3] * 3;
			}
			if (nextUglyNumber == next5) {
				i5++;
				next5 = uglyNumber[i5] * 5;
			}
		}
		return uglyNumber[n - 1];
	}

	//263. Ugly Number
	bool Solution::isUgly(int num) {
		if (num <= 0)
			return false;

		while (num % 5 == 0)
			num /= 5;
		while (num % 3 == 0)
			num /= 3;
		while ((num & 1) == 0)
			num /= 2;

		return num == 1;
	}

	//313. Super Ugly Number
	void Solution::test313() {
		vector<int> v313 = { 3,5,7,11,19,23,29,41,43,47 };
		nthSuperUglyNumber(15, v313);
	}

	int Solution::nthSuperUglyNumber(int n, vector<int>& primes) {
		if (n < 1 || primes.empty())
			return -1;

		vector<int> uglyNumbers(n, 1);
		multimap<int, pair<int, int>> nextUglyNumbers;
		for (auto n : primes)
			nextUglyNumbers.insert(pair<int, pair<int, int>>(n, pair<int, int>(0, n)));

		for (int i = 1; i < n; i++) {
			auto it = nextUglyNumbers.begin();
			uglyNumbers[i] = it->first;
			for (int size = nextUglyNumbers.size(); size > 0; size--) {
				if (it->first != uglyNumbers[i])
					break;
				it->second.first++;
				nextUglyNumbers.insert(pair<int, pair<int, int>>(uglyNumbers[it->second.first] * it->second.second, it->second));
				it = nextUglyNumbers.erase(it);
			}
		}

		return uglyNumbers[n - 1];
	}

	int Solution::TestGitHub() {
		minstd_rand0 generator((unsigned int)time(NULL));
		
		return generator() % 1000;
	}

	void Solution::test_priority_queue() {
	    std::cout << "Test priority_queue: " << std::endl;
	    std::vector<int> myints = {30, 5, 53, 60, 23, 31, 7,88};
	    std::priority_queue<int> mypque(myints.begin(), myints.end());
	    std::priority_queue<int, std::vector<int>, std::greater<int>> mypque1(myints.begin(),myints.end());
	    while (!mypque.empty()) {
	        std::cout << ' ' << mypque.top();
	        mypque.pop();
	    }
	    std::cout << std::endl;
	    while (!mypque1.empty()) {
	        std::cout << ' ' << mypque1.top();
	        mypque1.pop();
	    }

	    return;
	}

	void Solution::test_map() {
	    std::cout << std::endl <<"test map: "<<std::endl;
	    //std::map<char, int, clacomp> mymap = {{'a', 1}, {'b', 2}};
        std::map<char, int, std::greater<char>> mymap = {{'a', 1}, {'b', 2}};
        mymap.insert({'c', 3});
	    for(auto const &m : mymap) {
	        std::cout << m.first << "  " << "  ";
	    }
	}