    #include <iostream>
    #include <vector>
    using namespace std;
     
    #define SIZE (100000+10)
    #define leftChild(index) (2*index + 1)
    #define rightChild(index) (2*index + 2)
     
    int N, Q;
    vector<unsigned int> arr;
     
    struct SegmentTreeNode {
      vector<unsigned int> elements;
     
      SegmentTreeNode() {
        elements.clear();
      }
      
      void setValue(unsigned int value) {
        elements.clear();
        elements.emplace_back(value);
      }
     
      SegmentTreeNode operator=(const SegmentTreeNode& other) {
        for (unsigned int i = 0; i < other.elements.size(); i++)
          this->elements.emplace_back(other.elements[i]);
        return *this;
      }
      
      bool isValid() {
        unsigned int size = this->elements.size();
        if (size >= 3 && (this->elements[size - 1] + this->elements[size - 2] > this->elements[size - 3]))
          return true;
        return false;
      }
     
      unsigned int perimeter() {
        if (isValid() == false)
          return 0;
        int size = this->elements.size() - 1;
        return this->elements[size] + this->elements[size - 1] + this->elements[size - 2];
      }
     
      void merge(const SegmentTreeNode& left, const SegmentTreeNode& right) {
        unsigned int leftIndex = 0;
        unsigned int rightIndex = 0;
        this->elements.clear();
        while (leftIndex < left.elements.size() && rightIndex < right.elements.size()) {
          if (left.elements[leftIndex] < right.elements[rightIndex])
            this->elements.emplace_back(right.elements[rightIndex++]);
          else
            this->elements.emplace_back(left.elements[leftIndex++]);
     
          if (isValid() == true)
            break;
        }
     
        if (isValid() == false) {
          while (leftIndex < left.elements.size()) {
            this->elements.emplace_back(left.elements[leftIndex++]);
            if (isValid() == true)
              break;
          }
     
          while (rightIndex < right.elements.size()) {
            this->elements.emplace_back(right.elements[rightIndex++]);
            if (isValid() == true)
              break;
          }
        }
      }
    };
    SegmentTreeNode nodes[3 * SIZE];
     
    class SegmentTree {
     
      void buildTree(int parentIndex, int leftIndex, int rightIndex) {
        if (leftIndex > rightIndex)
          return;
     
        if (leftIndex == rightIndex) {
          nodes[parentIndex].setValue(arr[leftIndex]);
          return;
        }
     
        int middleIndex = (leftIndex + rightIndex) / 2;
        buildTree(leftChild(parentIndex), leftIndex, middleIndex);
        buildTree(rightChild(parentIndex), middleIndex + 1, rightIndex);
     
        nodes[parentIndex].merge(nodes[leftChild(parentIndex)], nodes[rightChild(parentIndex)]);
      }
     
      SegmentTreeNode queryUtil(int parentIndex, int leftIndex, int rightIndex, int leftQueryIndex, int rightQueryIndex) {
        if (rightQueryIndex < leftIndex || rightIndex < leftQueryIndex)
          return SegmentTreeNode();
     
        if (leftQueryIndex <= leftIndex && rightIndex <= rightQueryIndex)
          return nodes[parentIndex];
     
        int middleIndex = (leftIndex + rightIndex) / 2;
        SegmentTreeNode left = queryUtil(leftChild(parentIndex), leftIndex, middleIndex, leftQueryIndex, rightQueryIndex);
        SegmentTreeNode right = queryUtil(rightChild(parentIndex), middleIndex + 1, rightIndex, leftQueryIndex, rightQueryIndex);
     
        SegmentTreeNode result;
        result.merge(left, right);
        return result;
      }
     
      void updateUtil(int parentIndex, int leftIndex, int rightIndex, int updateIndex, unsigned int updateValue) {
        if (updateIndex < leftIndex || rightIndex < updateIndex)
          return;
     
        if (leftIndex == rightIndex && rightIndex == updateIndex) {
          nodes[parentIndex].setValue(updateValue);
          return;
        }
     
        int middleIndex = (leftIndex + rightIndex) / 2;
        updateUtil(leftChild(parentIndex), leftIndex, middleIndex, updateIndex, updateValue);
        updateUtil(rightChild(parentIndex), middleIndex + 1, rightIndex, updateIndex, updateValue);
     
        nodes[parentIndex].merge(nodes[leftChild(parentIndex)], nodes[rightChild(parentIndex)]);
      }
     
    public:
      void init() {
        buildTree(0, 0, N - 1);
      }
     
      unsigned int query(int leftIndex, int rightIndex) {
        SegmentTreeNode node = queryUtil(0, 0, N - 1, leftIndex, rightIndex);
        return node.perimeter();
      }
     
      void update(int index, unsigned int value) {
        arr[index] = value;
        updateUtil(0, 0, N - 1, index, value);
      }
    };
    SegmentTree tree;
     
    int main()
    {
      unsigned int number;
      cin >> N >> Q;
      for (int i = 0; i < N; i++) {
        cin >> number;
        arr.emplace_back(number);
      }
      tree.init();
     
      int type, lIndex, rIndex, position;
      unsigned int value;
      for (int i = 0; i < Q; i++) {
        cin >> type;
     
        if (type == 1) {
          cin >> position >> value;
          tree.update(position - 1, value);
        }
        else {
          cin >> lIndex >> rIndex;
          cout << tree.query(lIndex - 1, rIndex - 1) << endl;
        }
      }
     
      return 0;
    } 