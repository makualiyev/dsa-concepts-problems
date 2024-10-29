class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        i = 0
        j = 0
        while True:
            if (i <= len(s)) and (j <= len(p)):
                print("unsusccessful")
                break
            elif (j <= len(p)):
                print("unsusccessful")
                break
            if s[i] == p[j]:
                continue
                


        return True



def main() -> None:
    s: str = "aaa"
    p: str = "a*a"

    result: bool = Solution().isMatch(s, p)
    print(f"Testcase:\ns:{s}\tp:{p}\nResult:{result}")

        


if __name__ == '__main__':
    main()