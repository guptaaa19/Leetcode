class Solution {
public:
    int minLength(string s) {
        size_t pos1, pos2;
        
        while (true) {
            pos1 = s.find("AB");
            pos2 = s.find("CD");

            if (pos1 == std::string::npos && pos2 == std::string::npos) {
                break;
            }

            if (pos1 != std::string::npos) {
                s.erase(pos1, 2); // "AB" length is 2
            }

            if (pos2 != std::string::npos) {
                if (pos1 != std::string::npos && pos2 > pos1) {
                    pos2 -= 2;
                }
                s.erase(pos2, 2); // "CD" length is 2
            }
        }

        // Return the final length of the string
        return s.length();
    }
};
