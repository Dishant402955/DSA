uint8_t status[40000];
int dir[5]={0, 1, 0, -1, 0};
int q[40000], front=0, back=0;
int m, n;
class Solution {
public:
    static inline bool isOutside(int i, int j) {
        return i<0||i>=m||j<0||j>=n;
    }
    static inline int idx(int i, int j) { return i*n+j; }

    static void bfs(vector<vector<int>>& heights, uint8_t mark) {
        while (front!=back) {
            int ij=q[front++];
            auto [i, j]=div(ij, n);
            for (int a=0; a<4; a++) {
                int r=i+dir[a], s=j+dir[a+1];
                if (isOutside(r, s)) continue;
                int rs=idx(r, s);
                if ((status[rs]&mark)||heights[r][s]<heights[i][j])
                    continue;
                status[rs]|=mark;
                q[back++]=rs;
            }
        }
    }

    static vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m=heights.size();
        n=heights[0].size();
        memset(status, 0, m*n);

        front=back=0;// reset q
        // Pacific: top row + left col
        for (int j=0; j<n; j++) {
            const int ij=idx(0, j);
            status[ij]|=1;
            q[back++]=ij;
        }
        for (int i=1; i<m; i++) {
            const int ij=idx(i, 0);
            status[ij]|=1;
            q[back++]=ij;
        }
        bfs(heights, 1);

        // Atlantic: bottom row + right col
        front=back=0;// reset q
        for (int j=0; j<n; j++) {
            const int ij=idx(m-1, j);
            status[ij]|=2;
            q[back++]=ij;
        }
        for (int i=0; i<m-1; i++) {
            const int ij=idx(i, n-1);
            status[ij]|=2;
            q[back++]=ij;
        }
        bfs(heights, 2);

        vector<vector<int>> ans;
        for (int ij=0; ij<m*n; ij++) {
            if (status[ij]==3) {
                auto [i, j]=div(ij, n);
                ans.push_back({i, j});
            }
        }
        return ans;
    }
};
