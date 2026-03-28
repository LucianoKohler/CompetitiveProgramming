class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        
        # Find longest string and its length
        minWordLen = 201
        for word in strs: 
            minWordLen = min(len(word), minWordLen)

        if minWordLen == 0: return ""

        # Finding prefix
        pref = ""
        for i in range(0, minWordLen):
            pref += strs[0][i]
            for word in strs:
                if word[i] != pref[i]:
                    pref = pref[0:len(pref)-1]
                    return pref
        return pref
