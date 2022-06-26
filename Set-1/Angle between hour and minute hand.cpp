 	
 //Problem Name: Angle between hour and minute hand
 //Source : GeeksForGeeks
 /****************************************/
 int getAngle(int H , int M) {
        float hourPos = (H*30 + M *0.5); //Formula: (H%12 + M/60)* 30, where 30 = 360/12
        float minPos = (M*6); //6 = 360/60
        
        float firstAngle = abs(minPos - hourPos);
        
    
        float secondAngle = 360 - firstAngle;
        
        return (int) min(firstAngle,secondAngle);
    }