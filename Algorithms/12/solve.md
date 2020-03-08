## 思路

简单模拟.

### C++

```c++
class Solution {
public:
    string roman[13]={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    int number[13]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
    string intToRoman(int num) {
        string ans="";
        int pos=12;
        while(num){
            while(num>=number[pos]){
                num-=number[pos];
                ans+=roman[pos];
            }
            --pos;
        }
        return ans;
    }
};
```

### Java

```java
class Solution {
    String[] roman=new String[]{"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    int[] number=new int[]{1,4,5,9,10,40,50,90,100,400,500,900,1000};
    public String intToRoman(int num) {
        String ans="";
        int pos=12;
        while(num>0){
            while(num>=number[pos]){
                num-=number[pos];
                ans+=roman[pos];
            }
            --pos;
        }
        return ans;
    }
}
```

### Python

```python
class Solution:
    def intToRoman(self, num: int) -> str:
        roman = ['I','IV','V','IX','X','XL','L','XC','C','CD','D','CM','M']
        number = [1,4,5,9,10,40,50,90,100,400,500,900,1000]
        ans=''
        for i in range(len(number)-1,-1,-1):
            if num>=number[i]:
                ans+=num//number[i]*roman[i]
                num%=number[i]
        return ans
```

