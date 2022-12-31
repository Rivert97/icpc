#include <iostream>
#include <string>
#include <stack>
#include <bits/stdc++.h>

void get_right_padding_string(std::string &str, long unsigned int n, char padChar = ' ') {
    if (n <= str.size()) {
        return;
    }
 
    str.insert(str.size(), n - str.size(), padChar);
}

int find_in_array(std::string needle, std::string haystack[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (haystack[i].compare("") == 0) {
            break;
        }
        if (needle.compare(haystack[i]) == 0) {
            break;
        }
    }

    return i;
}

void sort_line(std::string &input) {
    sort(input.begin(), input.end());
}

int main() {
    const int MAX_WORDS_IN_DICT = 50;

    std::string indices[MAX_WORDS_IN_DICT];
    std::string sorted_indices[MAX_WORDS_IN_DICT];
    std::string dictionary[MAX_WORDS_IN_DICT];

    std::string line;
    int dict_idx;
    while (std::getline(std::cin, line)) {
        // Sort inner characters
        std::string original = line;
        sort_line(line);

        // Find the index in the dictionary
        dict_idx = find_in_array(line, indices, MAX_WORDS_IN_DICT);

        // Store the item in the indices and in the dictionary
        indices[dict_idx] = line;
        sorted_indices[dict_idx] = line;
        int cur_length = dictionary[dict_idx].length();
        if (cur_length > 0 && cur_length % 65 == 0) {
            dictionary[dict_idx] += "\n             ";
        }
        get_right_padding_string(original, 12);
        dictionary[dict_idx] += " " + original;
    }

    // Print the dictionary
    std::sort(std::begin(sorted_indices), std::end(sorted_indices));
    int i;
    int index;
    for (i = 0; i < MAX_WORDS_IN_DICT; i++) {
        if (sorted_indices[i].compare("") == 0) {
            continue;
        }
        index = find_in_array(sorted_indices[i], indices, MAX_WORDS_IN_DICT);
        get_right_padding_string(indices[index], 12);
        std::cout << indices[index] << ":" << dictionary[index] << std::endl;
    }

    return 0;
}

