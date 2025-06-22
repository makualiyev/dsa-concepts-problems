class Solution:
    def romanToInt(self, s: str) -> int:
        numerals = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000
        }
        numerals_2 = {
            "IV": 4,
            "IX": 9,
            "XL": 40,
            "XC": 90,
            "CD": 400,
            "CM": 900
        }

        parts = []
        i = 0

        while not (i == len(s)):
            if not ((i + 1) >= len(s)):
                if numerals[s[i]] < numerals[s[(i + 1)]]:
                    try:
                        parts.append(numerals_2[(s[i:(i+2)])])
                    except KeyError as e:
                        print(s[i], s[(i + 1)], i, (i + 1))
                    i += 2
                    continue
            parts.append(numerals[s[i]])
            i += 1
        
        return sum(parts)