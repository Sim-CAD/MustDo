void stockBuySell(int price[], int n) {
    if(n < 2)
        return;
        
    int buy = 0;
    int sell = buy + 1;
    vector<pair<int,int>> ans;
    int i = 0;
    
    for(int i = 0; i < n; i++){
        if(price[i + 1] > price[i]){
           
            buy = i;
            sell = i;
            
            while(sell < n - 1 && price[sell] < price[sell + 1])
                sell++;
            
            if(sell > buy)
                ans.push_back({buy, sell});
            
            i = sell;
        }
    }
    
    if(ans.empty()) cout<<"No Profit";
    else{
        for(auto i: ans){
            cout<<"("<<i.first<<" "<<i.second<<") ";
        }
    }
    cout<<endl;
}