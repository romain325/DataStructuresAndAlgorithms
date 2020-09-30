# Doubly Linked List

![Linked List](assets1.png)  

The doubly linked list is composed of node with one pointer to the next node and one to the previous node, the last next node is a pointer to the first node.  
The "linked list" object itself (The blue dot) is a pointer to the last node of the linked list.  
With the previous and next pointer we can easily go through the linked list

## Data Structure Operation Complexity  

| Condition | Access | Search | Insertion | Deletion |
| --------- | ------ | ------ | --------- | -------- |  
| Average   | Θ(n)   | Θ(n)   | Θ(1)      | Θ(1)     |
| Worst     | O(n)   | O(n)   | O(1)      | O(1)     |
