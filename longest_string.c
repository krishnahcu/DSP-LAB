#include <stdio.h>
int main()
{
  int test;
  scanf("%d",&test);
  while(test--){
    char a[1001];
    scanf("%s",a);
    int longestSubstring = 1, start=0, end = 0;
    //Odd palindromic substrings
    for(int i=1;i<strlen(a); i++){
      int j= i-1, k=i;
      while( j>=0 && k<strlen(a) && a[j]==a[k] ){
        if( k-j+1 > longestSubstring){
          start = j;
          end = k;
          longestSubstring = k-j+1;
        }
        j--;
        k++;
      }
    }
    //Even palindromic substring
    for(int i=0; i<strlen(a); i++){
      int j= i-1, k=i+1;
      while( j>=0 && k<strlen(a) && a[j]==a[k] ){
        if( k-j+1 > longestSubstring){
          start = j;
          end = k;
          longestSubstring = k-j+1;
        }
        j--;
        k++;
      }
    }
    for(int i=start; i<=end; i++ )
      printf("%c",a[i]);
    printf("\n");
  }
  return 0;
}
