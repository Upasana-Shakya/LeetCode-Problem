class Solution:
    def repeatedCharacter(self, s: str) -> str:
        st = set()
        for i in range(len(s)):
            if s[i] in st:
                return s[i]
            st.add(s[i])

            