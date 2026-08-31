//字典树 Trie

//高效地存储和查找字符串集合 字典形式
//实现树结构
#include <bits/stdc++.h>
using namespace std;


const int N=3000005;
int son[N][62],cnt[N],idx,n,q;//下标是0的点，既是根节点又是空节点
char s[N];

//插入
void insert(char str[]){
    //从根节点开始从前往后遍历
    int p=0;
    for(int i=0;str[i];i++){  //str[i]末尾是'\0'不用担心
        int u;
        //对应的子节点编号
        if(str[i]>='A'&&str[i]<='Z') u=str[i]-'A';
        else if(str[i]>='a'&&str[i]<='z') u=str[i]-'a'+26;
        else u=str[i]-'0'+52;
        if(!son[p][u]) son[p][u]=++idx;
        p=son[p][u];
        //每个经过的节点计数+1
        cnt[p]++;
    }
}

//查找
int query(char str[]){
    int p=0;
    for(int i=0;str[i];i++){
        int u=0;
        if(!son[p][u]) return 0;
        p=son[p][u];
    }
    //返回以p结尾的单词数量
    return cnt[p];
}

int main(){
    int T;
    cin>>T;
    while(T--){
        memset(son[0],0,sizeof(int)*(idx+1)*62);
        memset(cnt,0,sizeof(int)*(idx+1)*62);
        idx=0;
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++){
            scanf("%s",s);
            insert(s);
        }
        for(int i=1;i<=q;i++){
            scanf("%s",s);
            printf("%d\n",query(s));
        }
    }
    return 0;
}



//ai修改
#include <bits/stdc++.h>
using namespace std;

const int N = 3000005;          // 总字符数 ≤ 3e6，节点数不超过总长度 + 1
int son[N][62], cnt[N], idx;    // 62 = 26大写 + 26小写 + 10数字
char s[N];

// 字符 → 编号 0~61
inline int get_u(char c) {
    if (c >= 'A' && c <= 'Z') return c - 'A';
    if (c >= 'a' && c <= 'z') return c - 'a' + 26;
    return c - '0' + 52;
}

void insert(char str[]) {
    int p = 0;
    for (int i = 0; str[i]; ++i) {
        int u = get_u(str[i]);
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
        cnt[p]++;                 // 路径上每个节点计数 +1
    }
}

int query(char str[]) {
    int p = 0;
    for (int i = 0; str[i]; ++i) {
        int u = get_u(str[i]);
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        // 重置上一组数据使用的节点（son 和 cnt）
        // 注意：idx 是上一组数据的最大节点编号
        memset(son[0], 0, sizeof(int) * (idx + 1) * 62);
        memset(cnt, 0, sizeof(int) * (idx + 1));
        idx = 0;

        int n, q;
        scanf("%d%d", &n, &q);
        for (int i = 0; i < n; ++i) {
            scanf("%s", s);
            insert(s);
        }
        for (int i = 0; i < q; ++i) {
            scanf("%s", s);
            printf("%d\n", query(s));
        }
    }
    return 0;
}