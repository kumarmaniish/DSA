#include <iostream>
#include <vector>
#include <map>

int main() {
    std::vector<int> nums = {1, 2, 2, 3, 1, 4, 2, 5, 3, 5};
    std::map<int, int> mp;

    for(int i = 0; i < nums.size(); i++){
        // Use nums[i] as the key to count occurrences of values
        mp[nums[i]]++;
    }

    // Display the counts
    for(const auto& pair : mp) {
        std::cout << "Number " << pair.first << " occurs " << pair.second << " times." << std::endl;
    }

    return 0;
}
