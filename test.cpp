#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class PTLinkedList
{
    struct Node    // Khai báo 1 cấu trúc dữ liệu cho 1 node
    {
        int data_;
        Node* p_next_;
    };
 
public:
    PTLinkedList() { p_head_ = NULL; }
    ~PTLinkedList()
    {
        Node* head = p_head_;
        while (head)
        {
            Node* temp = head;
            head = head->p_next_;
            delete temp;
            temp = NULL;
        }
    }
 
    void AddValue(int val)  // Thêm 1 phần tử mới vào đầu danh sách
    {
        Node* new_node = new Node();
        new_node->data_ = val;
        new_node->p_next_ = p_head_;
        p_head_ = new_node;
    }
    void Remove()  // Loại bỏ phần từ đầu danh sách
    {
        if (p_head_ != NULL)
        {
            Node* temp = p_head_;
            p_head_ = p_head_->p_next_;
            delete temp;
        }
    }
    
    void Show()  // Viết thêm một hàm hiển thị
    {
        Node* temp = p_head_;
        while (temp != NULL)
        {
            int value = temp->data_;
            std::cout << "  " << value;
            temp = temp->p_next_;
        }
    }
private:
    Node* p_head_;   // Luôn có 1 con trỏ pHead quản lý phần tử đầu.
};
void sphenic(ll n){
		PTLinkedList data_list;
		int a = 0, check = 1;
		ll temp = n;
		for(int i = 2; i <= n; i++){
			if(n % i == 0){
				data_list.AddValue(i);
				a ++;
				int dem = 0;
				while(n % i == 0){
					n = n / i;
					dem ++;
				}
				if(dem > 1){
					check = 0;
					break;
				} 
			}	
		}
		//if((a == 3) && (check == 1)) cout << temp << " ";
		// cho cau 2
		if((a == 3) && (check == 1)){
			cout << temp << ": ";
			data_list.Show();
			cout << "\n";
		}
	if(temp >= 30) sphenic(temp-1);
}
int main(){
	ll n;
	cin >> n;
	sphenic(n);
}
