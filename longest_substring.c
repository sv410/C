#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char *s) {
    int lastIndex[256]; // Assuming ASCII characters
    for (int i = 0; i < 256; i++) {
        lastIndex[i] = -1; // Initialize all indices to -1
    }
    
    int maxLength = 0;
    int left = 0; // Left pointer of the window

    for (int right = 0; s[right] != '\0'; right++) {
        // If the character is found in the current substring
        if (lastIndex[(unsigned char)s[right]] >= left) {
            left = lastIndex[(unsigned char)s[right]] + 1; // Move the left pointer
        }
        
        lastIndex[(unsigned char)s[right]] = right; // Update the last index of the character
        int currentLength = right - left + 1; // Calculate the current length
        if (currentLength > maxLength) {
            maxLength = currentLength; // Update max length if current is greater
        }
    }

    return maxLength;
}

int main() {
    char input[] = "abcabcbb";
    int result = lengthOfLongestSubstring(input);
    printf("The length of the longest substring without repeating characters is: %d\n", result);
    return 0;
}
