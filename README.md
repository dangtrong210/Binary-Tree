# BINARY TREE (Cây nhị phân)
## 1. Khái niệm:
Cây là một tập hợp các phần tử (nút của cây) trong đó có 1 nút đặc biệt được gọi là gốc, 
các nút còn lại được chia thành những tập rời nhau theo quan hệ phân cấp trong đó nút khác gốc cũng là một cây. Mỗi nút ở cấp i sẽ quản lý một số nút ở cấp i+1.

<img src="https://images.viblo.asia/full/e09fad1d-478b-4f80-b61b-cd10499908f8.jpg" alt="Cây nhị phân">

Cây nhị phân là cây có bậc cao nhất của nút là 2.
## 2. Một số thao tác trên cây nhị phân:
2.1. Duyệt các phần tử:
<table border="1" style="width:100%; border-collapse: collapse; font-family: sans-serif;">
  <thead>
    <tr style="background-color: #f2f2f2;">
      <th style="padding: 10px;">NLR: NODE-LEFT-RIGHT (Pre-order)</th>
      <th style="padding: 10px;">LNR: LEFT-NODE-RIGHT (In-order)</th>
      <th style="padding: 10px;">LRN: LEFT-RIGHT-NODE (Post-order)</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td style="padding: 10px; vertical-align: top;">
        <pre><code>
void NLR(NODE *root){
	if (root != NULL){
    //thao-tác;
		NLR(root->left);
		NLR(root->right);
	}
}
        </code></pre>
      </td>
      <td style="padding: 10px; vertical-align: top;">
        <pre><code>
void LNR(NODE *root){
	if (root != NULL){
		LNR(root->left);
    //thao-tác;
		LNR(root->right);
	}
}
        </code></pre>
      </td>
      <td style="padding: 10px; vertical-align: top;">
        <pre><code>
void LRN(NODE *root){
	if (root != NULL){
		LRN(root->left);
		LRN(root->right);
    //thao-tác;
	}
}
        </code></pre>
      </td>
    </tr>
  </tbody>
</table>

> [!NOTE]
> Các thao tác duyệt các phần tử trên có thể dùng để: tìm nút, chèn vào vị trí, xóa nút lá, in các phần tử nút, ...

2.2. <a href="https://github.com/dangtrong210/Link-List?tab=readme-ov-file#2-m%E1%BB%99t-s%E1%BB%91-thao-t%C3%A1c-tr%C3%AAn-khi-s%E1%BB%AD-d%E1%BB%A5ng-link-list-trong-c" target="blank">Định nghĩa và tạo nút</a>: Về cơ bản giống như tạo một NODE.

2.3. Chèn nút mói vào vị trí nút lá:
````
NODE *insert(NODE *root, int value){
	if (root == NULL){
		return create(value);
	}
	if (root->data > value){
		root->left = insert(root->left, value);
	}
	else
		root->right = insert(root->right, value);
	return root;
}
````
2.4. Xóa nút ở vị trí bất kì:

Hàm tìm phần tử nhỏ nhất nhánh phải: (vào hàm del sẽ thấy tại sao phải khai báo hàm này)
````
struct NODE *findMinNODE(struct NODE *node)
{
	struct NODE *current = node;
	while (current && current->left != NULL)
	{
		current = current->left;
	}
	return current;
}
````
````
struct NODE *delNODE(struct NODE *root, int value)
{
	if (root == NULL)
	{
		return root;
	}
	if (root->data > value)                            //Tìm vị trí value cần xóa.
		root->left = delNODE(root->left, value);
	else if (root->data < value)
	{
		root->right = delNODE(root->right, value);
	}
	else
	{
		if (root->left == NULL && root->right == NULL) //Trường hợp 1: Value cần xóa không có con 
		{
			free(root);
			return NULL;
		}                                              //Trường hợp 2: Value cần xóa có 1 con 
		else if (root->left == NULL)                   // Value cần xóa không có con trái  
		{
			struct NODE *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)                   //Value cần xóa không có con phải
		{
			struct NODE *temp = root->left;
			free(root);
			return temp;
		}                                               //Trường hợp 3: Value cần xóa có 2 con
		struct NODE *temp = findMinNODE(root->right);   //Tìm nút lá nhỏ nhất ở nhánh phải
		root->data = temp->data;                        //Sao chép data của nút mới tìm được vào value
		root->right = delNODE(root->right, temp->data); //Xóa nút vừa tìm được 
	}
	return root;
}
````
