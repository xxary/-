#include<iostream>
#include<vector>
std::pair<unsigned long long,long>collatz(
    unsigned long long const limit)
{
    long length = 0;
    unsigned long long number=0;
    std::vector<int> endOne(limit + 1,0);
    
    for(unsigned long long i = 2;i<=limit;++i)
    {
        auto n = i;
        long steps = 0;
        while(n != 1 && n>=i)
        {
            if((n%2)==0)n = n/2;
            else n = n * 3 + 1;
            steps++;
        }
        endOne[i]=steps + endOne[n];
        
        if(endOne[i]>length)
        {
            length = endOne[i];
            number = i;
        }
    }
    return std::make_pair(number,length);
}

int main(){
    auto six = collatz(6);
    std::cout<<six.first<<",";
    std::cout<<six.second<<std::endl;
}
