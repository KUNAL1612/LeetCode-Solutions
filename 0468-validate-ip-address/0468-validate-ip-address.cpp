class Solution {
public:
    std::string validateIPv4(std::string IP) {
        std::vector<std::string> nums;
        std::stringstream ss(IP);
        std::string segment;
        
        while (std::getline(ss, segment, '.')) {
            nums.push_back(segment);
        }
        
        if (nums.size() != 4) return "Neither";
        
        for (const std::string& x : nums) {
            if (x.empty() || x.size() > 3) return "Neither";
            if (x[0] == '0' && x.size() != 1) return "Neither";
            for (char ch : x) {
                if (!std::isdigit(ch)) return "Neither";
            }
            if (std::stoi(x) > 255) return "Neither";
        }
        
        return "IPv4";
    }

    std::string validateIPv6(std::string IP) {
        std::vector<std::string> nums;
        std::stringstream ss(IP);
        std::string segment;
        
        while (std::getline(ss, segment, ':')) {
            nums.push_back(segment);
        }
        
        if (nums.size() != 8) return "Neither";
        
        std::string hexdigits = "0123456789abcdefABCDEF";
        
        for (const std::string& x : nums) {
            if (x.empty() || x.size() > 4) return "Neither";
            for (char ch : x) {
                if (hexdigits.find(ch) == std::string::npos) return "Neither";
            }
        }
        
        return "IPv6";
    }

    std::string validIPAddress(std::string IP) {
        int dots = std::count(IP.begin(), IP.end(), '.');
        int colons = std::count(IP.begin(), IP.end(), ':');
        
        if (dots == 3) {
            return validateIPv4(IP);
        } else if (colons == 7) {
            return validateIPv6(IP);
        } else {
            return "Neither";
        }
    }
};

// use stringstream and stack
// number between 0 and 255
// no leading zero