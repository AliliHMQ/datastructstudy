#include <iostream>
#include <vector>
#include <algorithm> // 用到 find 和 sort
using namespace std;

int main() {
    // 初始化：货架上的包裹编号（数据）
    vector<int> packages = {5, 2, 8, 1, 9};
    
    cout << "【原始货架】: ";
    for (int x : packages) cout << x << " "; // 这一行只是预览，不管它
    cout << endl;

    // ========== 功能1：最基本的“遍历”和“取值” ==========
    // 注意：auto it = packages.begin() 就相当于“拿起第一个包裹的地址”
    cout << "\n--- 功能1：挨个拆包查看（it是地址，*it是包裹）---" << endl;
    for (auto it = packages.begin(); it != packages.end(); ++it) {
        // 这里 it 是地址（比如门牌号），*it 才是包裹里的数字
        cout << "当前地址 it 指向的值是: " << *it << endl;
    }

    // ========== 功能2：通过迭代器“修改”数据 ==========
    // 需求：把货架上大于 5 的包裹，统统贴上“VIP”标签（改成 999）
    cout << "\n--- 功能2：把大于5的改成999（修改值）---" << endl;
    for (auto it = packages.begin(); it != packages.end(); ++it) {
        if (*it > 5) {      // 读取包裹内容判断
            *it = 999;      // 修改包裹内容（注意：改的是 *it，不是 it）
        }
    }
    cout << "修改后: ";
    for (int x : packages) cout << x << " "; 
    cout << endl;

    // ========== 功能3：查找特定位置（利用算法返回的迭代器） ==========
    // 需求：找到包裹 2 在哪个位置，并在它前面插入一个 666
    cout << "\n--- 功能3：查找并插入（迭代器做“书签”）---" << endl;
    auto find_it = find(packages.begin(), packages.end(), 2);
    
    if (find_it != packages.end()) {
        cout << "找到了 2，现在在它前面插入 666" << endl;
        // 这里 insert 返回新的有效迭代器，但我们暂时不管返回值
        packages.insert(find_it, 666); 
    }

    cout << "插入后: ";
    for (int x : packages) cout << x << " "; 
    cout << endl;

    // ========== 功能4：最关键的“删除+更新迭代器”（防止崩溃） ==========
    // 需求：把所有等于 999 的包裹扔掉
    // 注意：这里循环里没有写 ++it，因为 erase 会帮我们移到下一个
    cout << "\n--- 功能4：删除所有999（必须接收 erase 的返回值）---" << endl;
    auto it = packages.begin();
    while (it != packages.end()) {
        if (*it == 999) {
            // 重要！erase删掉当前地址的包裹，返回的是“下一个包裹的新地址”
            // 如果不接收这个新地址，it就变成野指针，程序必崩！
            it = packages.erase(it); 
        } else {
            ++it; // 没删掉，才自己往前走
        }
    }

    cout << "删除后: ";
    for (int x : packages) cout << x << " "; 
    cout << endl;

    // ========== 功能5：局部操作（展示迭代器区间的灵活性） ==========
    // 需求：只排序前3个包裹（第4、5个不动）
    cout << "\n--- 功能5：只排序前3个元素（区间就是地址范围）---" << endl;
    // packages.begin() + 3 就是“第3个位置的地址”，注意这是 vector 特有的随机访问
    sort(packages.begin(), packages.begin() + 3); 
    
    cout << "排序前3个后: ";
    for (int x : packages) cout << x << " "; 
    cout << endl;

    return 0;
}