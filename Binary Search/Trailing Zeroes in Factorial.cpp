// Find how many zeroes at the end in factorial value of given number

============================================================================================================================

// Brute Force==> First find factorial value of given number and then calculate how many zeroes in it

class Solution
{
public:
    int trailingZeroes(int N)
    {
        // find factorial of number
        int fact=1;
        for(int i=1;i<=N;i++){
            fact=fact*i;
        }
        
        int num=fact;
        int zeroCnt=0;
        //Now find how many zeroes in factorial value
        while(num%10==0){
            zeroCnt++;
            
            num=num/10;
        }
        
        return zeroCnt;
    }
};

==========================================================================================================================

// Optimal Solution==> Trailing zero in any number comes if 10 is divisor of that number
                       Factors of 10 are 2 and 5
                       For 10==> 2*5
                       For 20==>4*5

                      So, take 5

class Solution
{
public:
    int trailingZeroes(int N)
    {
        // Write Your Code here
        int cnt=0;
        
        while(N>0){
            cnt+=N/5;
            
            N=N/5;
        }
        
        return cnt;
    }
};
