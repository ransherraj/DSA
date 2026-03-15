/*****
1622. Fancy Sequence
Write an API that generates fancy sequences using the append, addAll, and multAll operations.

Implement the Fancy class:

Fancy() Initializes the object with an empty sequence.
void append(val) Appends an integer val to the end of the sequence.
void addAll(inc) Increments all existing values in the sequence by an integer inc.
void multAll(m) Multiplies all existing values in the sequence by an integer m.
int getIndex(idx) Gets the current value at index idx (0-indexed) of the sequence modulo 109 + 7. If the index is greater or equal than the length of the sequence, return -1.
 

Example 1:

Input
["Fancy", "append", "addAll", "append", "multAll", "getIndex", "addAll", "append", "multAll", "getIndex", "getIndex", "getIndex"]
[[], [2], [3], [7], [2], [0], [3], [10], [2], [0], [1], [2]]
Output
[null, null, null, null, null, 10, null, null, null, 26, 34, 20]

Explanation
Fancy fancy = new Fancy();
fancy.append(2);   // fancy sequence: [2]
fancy.addAll(3);   // fancy sequence: [2+3] -> [5]
fancy.append(7);   // fancy sequence: [5, 7]
fancy.multAll(2);  // fancy sequence: [5*2, 7*2] -> [10, 14]
fancy.getIndex(0); // return 10
fancy.addAll(3);   // fancy sequence: [10+3, 14+3] -> [13, 17]
fancy.append(10);  // fancy sequence: [13, 17, 10]
fancy.multAll(2);  // fancy sequence: [13*2, 17*2, 10*2] -> [26, 34, 20]
fancy.getIndex(0); // return 26
fancy.getIndex(1); // return 34
fancy.getIndex(2); // return 20
 

Constraints:

1 <= val, inc, m <= 100
0 <= idx <= 105
At most 105 calls total will be made to append, addAll, multAll, and getIndex.

**/

//Brute force
/**
1️⃣ Maintain a normal dynamic array arr.

2️⃣ append(val)
Push the value at the end of the array.

arr.push_back(val)

3️⃣ addAll(inc)
Traverse the entire array and add inc to each element.

for each element:
    arr[i] += inc

4️⃣ multAll(m)
Traverse the entire array and multiply each element by m.

for each element:
    arr[i] *= m

5️⃣ getIndex(idx)
Return the value at index idx.

return arr[idx]

6️⃣ If idx >= size, return -1.

7️⃣ Apply modulo 1e9+7 after every update to avoid overflow.

8️⃣ The array is always storing actual values.

9️⃣ Every global operation modifies all elements directly.

🔟 Complexity becomes too large because operations affect all elements.

Brute Force Complexity
Operation	Complexity
append	O(1)
addAll	O(n)
multAll	O(n)
getIndex	O(1)

Worst case:

10^5 operations × 10^5 elements
≈ 10^10 operations ❌

Too slow.

  **/

class Fancy {
public:
    vector<long long> arr;
    const int MOD = 1e9+7;

    Fancy() {}

    void append(int val) {
        arr.push_back(val);
    }

    void addAll(int inc) {
        for(int i=0;i<arr.size();i++)
            arr[i] = (arr[i] + inc) % MOD;
    }

    void multAll(int m) {
        for(int i=0;i<arr.size();i++)
            arr[i] = (arr[i] * m) % MOD;
    }

    int getIndex(int idx) {
        if(idx >= arr.size()) return -1;
        return arr[idx];
    }
};




// Optimised

/**


1️⃣ Notice that addAll and multAll apply the same transformation to every element.

2️⃣ Instead of updating the entire array, maintain two global variables:

mul → global multiplier
add → global addition

3️⃣ Any element’s real value can be represented as:

value = stored_value * mul + add

4️⃣ Initially:

mul = 1
add = 0

5️⃣ addAll(inc)
Update only the global addition.

add += inc

6️⃣ multAll(m)
Update both transformation variables.

mul *= m
add *= m

7️⃣ append(val)
We must store the number so that after transformation we get val.

Solve:

stored * mul + add = val

So:

stored = (val - add) / mul

8️⃣ Division under modulo is not allowed, so we use modular inverse.

stored = (val - add) * inverse(mul)

9️⃣ Store this normalized value in the array.

🔟 getIndex(idx)
Compute the final value using transformation.

value = stored * mul + add
Optimized Complexity
Operation	Complexity
append	O(log MOD)
addAll	O(1)
multAll	O(1)
getIndex	O(1)

Works easily for:

10^5 operations




*/

class Fancy {
public:
    const long long MOD = 1e9+7;

    vector<long long> arr;
    long long mul = 1;
    long long add = 0;

    long long power(long long a,long long b){
        long long res=1;
        while(b){
            if(b&1) res=(res*a)%MOD;
            a=(a*a)%MOD;
            b>>=1;
        }
        return res;
    }

    long long inverse(long long x){
        return power(x,MOD-2);
    }

    Fancy(){}

    void append(int val) {
        long long stored = ((val - add + MOD)%MOD) * inverse(mul) % MOD;
        arr.push_back(stored);
    }

    void addAll(int inc) {
        add = (add + inc)%MOD;
    }

    void multAll(int m) {
        mul = (mul*m)%MOD;
        add = (add*m)%MOD;
    }

    int getIndex(int idx) {
        if(idx>=arr.size()) return -1;
        return (arr[idx]*mul % MOD + add)%MOD;
    }
};
