//	Dynamic Planning
//	F[N] = Sigma(F[i] *F[N-1-i],i=[0,N-1]) 
class Solution {
	var numTreesArray = [Int]()
    func numTrees(_ n: Int) -> Int {
		numTreesArray.append(1)//0
		numTreesArray.append(1)//1
		numTreesArray.append(2)//2
		numTreesArray.append(5)//3
		if n<=3{
			return numTreesArray[n]
		}
		for var i in 4...n{
			numTreesArray.append(0)
			for var top in 0...(i-1){
				var tail = i - top - 1
				numTreesArray[i] += numTreesArray[top] * numTreesArray[tail]
			}
		}
		return numTreesArray[n]

    }
}