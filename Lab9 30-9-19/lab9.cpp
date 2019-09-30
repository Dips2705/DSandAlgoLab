#include<bits/stdc++.h>
using namespace std;
struct point {    
   int x, y;
};
point p0; 
point secondTop(stack<point> &stk) {
   point tempPoint = stk.top(); 
   stk.pop();
   point res = stk.top();  
   stk.push(tempPoint);      
   return res;
}

int squaredDist(point p1, point p2) {
   return ((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}
int direction(point a, point b, point c) {
   int val = (b.y-a.y)*(c.x-b.x)-(b.x-a.x)*(c.y-b.y);
   if (val == 0)
      return 0;    
   else if(val < 0)
      return 2;    
}
int comp(const void *point1, const void*point2) {
   point *p1 = (point*)point1;
   point *p2 = (point*)point2;
   int dir = direction(p0, *p1, *p2);
   if(dir == 0)
      return (squaredDist(p0, *p2) >= squaredDist(p0, *p1))?-1 : 1;
   return (dir==2)? -1 : 1;
}
vector<point> findConvexHull(point points[], int n) {
   vector<point> convexHullPoints;
   int minY = points[0].y, min = 0;
   for(int i = 1; i<n; i++) {
      int y = points[i].y;

      if((y < minY) || (minY == y) && points[i].x < points[min].x) {
         minY = points[i].y;
         min = i;
      }
   }
   swap(points[0], points[min]);    
   p0 = points[0];
   qsort(&points[1], n-1, sizeof(point), comp);    
   int arrSize = 1;   
   for(int i = 1; i<n; i++) {

      while(i < n-1 && direction(p0, points[i], points[i+1]) == 0)
         i++;
         points[arrSize] = points[i];
         arrSize++;
   }
   if(arrSize < 3)
      return convexHullPoints;    
      stack<point> stk;
      stk.push(points[0]); stk.push(points[1]); stk.push(points[2]);
   for(int i = 3; i<arrSize; i++) {    
      while(direction(secondTop(stk), stk.top(), points[i]) != 2)
         stk.pop();   
         stk.push(points[i]);
   }
   while(!stk.empty()) {
      convexHullPoints.push_back(stk.top());    
      stk.pop();
   }
}
int main() {
   // point points[] = {{-7,8},{-4,6},{2,6},{6,4},{8,6},{7,-2},{4,-6},{8,-7},{0,0},{3,-2},{6,-10},{0,-6},{-9,-5},{-8,-2},{-8,0},{-10,3},{-2,2},{-10,4}};
   int n;
   cin>>n;
   point points[n];
   for(int i=0;i<n;i++)
      cin>>points[i].x>>points[i].y;
   vector<point> result;
   result = findConvexHull(points, n);
   int min=INT_MAX;
   vector<point>::iterator it;
   vector<point>::iterator pos;
   pos=result.begin();
   cout<<result.size()<<endl;
   for(it = result.begin(); it!=result.end(); it++)
   {
      
      
      if(it->x<min)
      {
         min=it->x; 
         // cout<<min<<endl;
         pos=it; 
         // cout<<pos->x<<" "<<pos->y<<endl;
      }
   }
   // cout<<pos->x<<" "<<pos->y<<endl;
   for(it=pos;it!=result.end();it++)
      cout<<it->x<<" "<<it->y<<endl;
   for(it=result.begin();it!=pos;it++)
      cout<<it->x<<" "<<it->y<<endl;



}