#include <bits/stdc++.h>
#include<iostream>
#include<string.h>

using namespace std;

//Function to generate Parity Check
bool getParity(unsigned int n){
    bool parity = 0;
    while (n)
    {
        parity = !parity;
        n = n & (n - 1);
    }
    return parity;
}
// Function to generate hamming code
vector<int> generateHammingCode(
        vector<int> msgBits, int m, int r)
{
    // Stores the Hamming Code
    vector<int> hammingCode(r + m);

    // Find positions of redundant bits
    for (int i = 0; i < r; ++i) {

        // Placing -1 at redundant bits
        // place to identify it later
        hammingCode[pow(2, i) - 1] = -1;
    }
    int j = 0;
    // Iterate to update the code
    for (int i = 0; i < (r + m); i++) {

        // Placing msgBits where -1 is
        // absent i.e., except redundant
        // bits all positions are msgBits
        if (hammingCode[i] != -1) {
            hammingCode[i] = msgBits[j];
            j++;
        }
    }
    for (int i = 0; i < (r + m); i++) {

        // If current bit is not redundant
        // bit then continue
        if (hammingCode[i] != -1)
            continue;

        int x = log2(i + 1);
        int one_count = 0;

        // Find msg bits containing
        // set bit at x'th position
        for (int j = i + 2;
             j <= (r + m); ++j) {

            if (j & (1 << x)) {
                if (hammingCode[j - 1] == 1) {
                    one_count++;
                }
            }
        }
        // Generating hamming code for
        // even parity
        if (one_count % 2 == 0) {
            hammingCode[i] = 0;
        }
        else {
            hammingCode[i] = 1;
        }
    }
    // Return the generated code
    return hammingCode;

}

// Function to find the hamming code
// of the given message bit msgBit[]
void findHammingCode(vector<int>& msgBit)
{

    // Message bit size
    int m = msgBit.size();

    // r is the number of redundant bits
    int r = 1;

    // Find no. of redundant bits
    while (pow(2, r) < (m + r + 1)) {
        r++;
    }
    // Generating Code
    vector<int> ans
            = generateHammingCode(msgBit, m, r);

    // Print the code
    cout << "\nMessage bits are:\n";
    for (int i = 0; i < msgBit.size(); i++)
        cout << msgBit[i] << " ";

    cout << "\nHamming code is:\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}

int main()
{

    // Given message bits for Hamming Code
    vector<int> msgBit = { 0, 1, 0, 1 };

    // Function Call Hamming Code
    findHammingCode(msgBit);

    unsigned int n = 1101;
    cout <<"\nPlease enter a number for the parity check:\n";
    cin >> n;
    cout<<"Parity of number "<<n<<" = "<<(getParity(n)? "odd": "even");
    getchar();

    char a[20],b[20];
    char sum[20],complement[20];
    int i;

    cout<<"\nEnter first binary string\n";
    cin>>a;
    cout<<"Enter second binary string\n";
    cin>>b;

    if(strlen(a)==strlen(b))
    {
        char carry='0';
        int length=strlen(a);

        for(i=length-1;i>=0;i--)
        {
            if(a[i]=='0' && b[i]=='0' && carry=='0')
            {
                sum[i]='0';
                carry='0';
            }
            else if(a[i]=='0' && b[i]=='0' && carry=='1')
            {
                sum[i]='1';
                carry='0';

            }
            else if(a[i]=='0' && b[i]=='1' && carry=='0')
            {
                sum[i]='1';
                carry='0';

            }
            else if(a[i]=='0' && b[i]=='1' && carry=='1')
            {
                sum[i]='0';
                carry='1';

            }
            else if(a[i]=='1' && b[i]=='0' && carry=='0')
            {
                sum[i]='1';
                carry='0';

            }
            else if(a[i]=='1' && b[i]=='0' && carry=='1')
            {
                sum[i]='0';
                carry='1';

            }
            else if(a[i]=='1' && b[i]=='1' && carry=='0')
            {
                sum[i]='0';
                carry='1';

            }
            else if(a[i]=='1' && b[i]=='1' && carry=='1')
            {
                sum[i]='1';
                carry='1';

            }
            else
                break;
        }
        cout<<"\nSum="<<carry<<sum;

        for(i=0;i<length;i++)
        {
            if(sum[i]=='0')
                complement[i]='1';
            else
                complement[i]='0';
        }

        if(carry=='1')
            carry='0';
        else
            carry='1';

        cout<<"Checksum="<<carry<<complement;
    }
    else
        cout<<"Wrong input strings";
    
    return 0;
}
