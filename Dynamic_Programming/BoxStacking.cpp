class Cube{
    public:
      int h;
      int w;
      int l;
    };
    int maxHeight(int height[],int width[],int length[],int n)
    {
        //Your code here
        int size = 3 * n;
        Cube arr[size];
        int index = 0;
        for(int i = 0 ; i < n ; i++){
            arr[index].h = height[i];
            arr[index].w = max(width[i],length[i]);
            arr[index].l = min(width[i],length[i]);
            index++;
            
            arr[index].h = width[i];
            arr[index].w = max(height[i],length[i]);
            arr[index].l = min(height[i],length[i]);
            index++;
            
            arr[index].h = length[i];
            arr[index].w = max(width[i],height[i]);
            arr[index].l = min(width[i],height[i]);
            index++;
        }
        sort(arr,arr+size,[](Cube&a,Cube&b){
            return a.w * a.l > b.w * b.l;
        });
        vector<int> dp(size,0);
        for(int i = 0 ; i < size ; i++){
            dp[i] = arr[i].h;
        }
        for(int i = 1; i < size ; i++){
            for(int j = 0 ; j < i ; j++){
                if(arr[i].w < arr[j].w and arr[i].l < arr[j].l and arr[i].h + dp[j] > dp[i]){
                    dp[i] = arr[i].h + dp[j];
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
