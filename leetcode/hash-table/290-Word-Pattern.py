
# Python 大法好!
class Solution(object):
    def wordPattern(self, pattern, s):
        words = s.split()

        if len(words) != len(pattern):
            return False

        record = dict()

        for key, value in zip(pattern, words):
            if key in record:
                if record[key] != value:
                    return False
            elif value in record.values():
                return False
            else:
                record[key] = value

        return True
