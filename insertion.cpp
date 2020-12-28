#include <iostream>

class Node
{
    public:
        int data_;
        Node* next_;
        Node(int d, Node* n = nullptr) : data_{ d }, next_{ n } {}
};

class LinkedList
{
    public:
        Node* head_;
        LinkedList() { head_ = nullptr; }
        void AddNodeByIntToTheEndOfTheList(int int_data)
        {
            Node* new_node = new Node(int_data);
            Node* temp = head_;
            if(!head_) 
            {
                head_ = new_node;
                return;
            }
            while(temp->next_ != nullptr)
                temp = temp->next_;
            temp->next_ = new_node;
            return;
        }

        void AddNodeWithAnotherNode(Node* node_to_add)
        {
            Node* temp = head_;
            if(!head_) {
                head_ = node_to_add;
                return;
            }
            while(temp->next_)
                temp = temp->next_;
                temp->next_ = node_to_add;
                return;
        }

        void DeleteNodeInt(int int_to_delete)
        {
            Node* temp = head_;
            Node* prev = head_;
            if(!head_)
                return;
            if(head_->data_ == int_to_delete)
            {
                head_ = temp->next_;
                delete(temp);
                return;
            }
            while(temp!= nullptr && temp->data_ != int_to_delete)
            {
                prev = temp;
                temp = temp->next_;
            }
            if(temp == nullptr)
            {
                std::cout << int_to_delete << " does not exist";
                return;
            }
            prev->next_ = temp->next_;
            std::cout<< int_to_delete<< " was found and successfully delted!";
            delete(temp);
        }

        void PrintList()
        {
            if(!head_)
            {
                std::cout << "List is empty!\n";
                return;
            }
            Node* temp = head_;
            std::cout<<"*** Printing List...***\n";
            for(;temp!=nullptr;temp = temp->next_)
            {
                std::cout<< temp->data_ << "  ";
            }
            std::cout << "\n";
        }

        void LoopDetection()
        {
            Node* slow = head_, *fast = head_;
            while (slow && fast && fast->next_)
            {
                slow = slow->next_;
                fast = fast->next_->next_;
                if(slow == fast)
                {
                    std::cout<< "There is a loop\n";
                    return;
                }
            }
            std::cout<< "The middle of the list is : " << slow->data_;
        }

        Node* MergeTwoSortedLists(Node* sorted_list_to_merge)
        {
            Node* res = new Node(0);
            Node* iterator = res;
            Node* current_list = this->head_;
            while(current_list && sorted_list_to_merge)
            {
                if(current_list->data_ < sorted_list_to_merge->data_)
                {
                    iterator->next_ = current_list;
                    current_list = current_list->next_;
                }
                else
                {
                    iterator->next_ = sorted_list_to_merge;
                    sorted_list_to_merge = sorted_list_to_merge->next_;
                }
                iterator = iterator->next_;
            }
            iterator->next_ = (current_list!= nullptr) ? current_list : sorted_list_to_merge;
            return res->next_;
        }
;
        friend void PrintListVersion2(Node* head);
};

void PrintListVersion2(Node* head)
{
    while(head)
    {
        std::cout << head->data_ << " ";
        head = head->next_;
    }
}

int main() {

    LinkedList my_list;
    Node* n1 = new Node(1);
    Node* n2 = new Node(4);
    Node* n3 = new Node(9);
    Node* n4 = new Node(-8);
    Node* n5 = new Node(50);
    my_list.AddNodeWithAnotherNode(n1);
    my_list.AddNodeWithAnotherNode(n2);
    my_list.AddNodeWithAnotherNode(n3);
    my_list.AddNodeWithAnotherNode(n4);
    my_list.AddNodeWithAnotherNode(n5);
    my_list.LoopDetection();
    n5->next_ = n2;
    std::cout << "---------------------------------------------------\n";
    my_list.LoopDetection();

    LinkedList* l2 = new LinkedList();
    l2->AddNodeByIntToTheEndOfTheList(1);
    l2->AddNodeByIntToTheEndOfTheList(3);
    l2->AddNodeByIntToTheEndOfTheList(4);
    l2->AddNodeByIntToTheEndOfTheList(5);
    l2->AddNodeByIntToTheEndOfTheList(9);

    LinkedList* l3 = new LinkedList();
    l3->AddNodeByIntToTheEndOfTheList(2);
    l3->AddNodeByIntToTheEndOfTheList(6);
    l3->AddNodeByIntToTheEndOfTheList(7);
    l3->AddNodeByIntToTheEndOfTheList(8);

    Node* result_list = l2->MergeTwoSortedLists(l3->head_);

    PrintListVersion2(result_list);
    
    return 0;
}