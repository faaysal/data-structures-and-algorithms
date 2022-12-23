class Node:
    def __init__(self, val):
        self.val = val
        self.next = None


class Linked_List:
    def __init__(self):
        self.head = None

    def display(self):
        temp = self.head

        while temp != None:
            print(temp.val)
            temp = temp.next

    def insert_at_head(self, val):
        new_node = Node(val)
        if self.head == None:
            self.head = new_node
        else:
            new_node.next = self.head
            self.head = new_node

    def insert_at_tail(self, val):
        new_node = Node(val)
        if self.head == None:
            self.head = new_node
        else:
            temp = self.head
            while temp.next != None:
                temp = temp.next

            temp.next = new_node
