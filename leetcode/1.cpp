#include <stdio.h>

bool checkRecord(char * s){
    char * p = s;

    int Absent = 0;
    int Late = 0;
    while (*p != '\0')
    {
        if (*p == 'A') {
            Absent ++;
            if (Absent >= 2) {
                return false;
            }
        }
        if (*p == 'L'){
            Late ++;
            if (Late >= 3) {
                return false;
            }
        }
        if (*p == 'P' || *p == 'A') {
            Late = 0;
        }
        p++;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    char s[] = "PALLP";
    printf("%d", checkRecord(s));
    return 0;
}


/**
 * class Solution(object):
    def checkRecord(self, s):
        """
        :type s: str
        :rtype: bool
        """
        late, absent = 0,0

        for i in s:
            if i == 'A':
                absent += 1
                if absent >= 2:
                    return False
            
            if i == 'L':
                late += 1
                if late >= 3:
                    return False
            
            if i == 'P' or i == 'A':
                late = 0
        
        return True
 */ 