class Solution {
public:
    int binaryToDecimal(const std::string& binary) {
    int decimal = 0;
    int n = binary.length();

    for (int i = 0; i < n; i++) {
        if (binary[i] == '1') {
            decimal += pow(2, n - 1 - i);
        }
    }

    return decimal;
}

    int getDecimalValue(ListNode* head) {
        string num="";
        while(head!=NULL){
            num=num+to_string(head->val);
            head=head->next;
        }

        return (int)binaryToDecimal(num);
    }
};
