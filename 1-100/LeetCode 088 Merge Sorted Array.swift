//
//	以最优的效率合并有序的nums1和nums2
//	新array从尾到头进行生成
//

class Solution {
	func merge(_ nums1: inout [Int], _ m: Int, _ nums2: [Int], _ n: Int) {
		var Index_nums1 = m-1
		var Index_nums2 = n-1
		var Index_nums_total = n+m-1
		if nums1 == nil || nums2 == nil{
			return
		} 
		while Index_nums1>=0 && Index_nums2>=0{
			if nums1[Index_nums1] > nums2[Index_nums2]{
				nums1[Index_nums_total] = nums1[Index_nums1]
				Index_nums_total -= 1
				Index_nums1 -= 1
			}
			else {
				nums1[Index_nums_total] = nums2[Index_nums2]
				Index_nums_total -= 1
				Index_nums2 -= 1
			}
		}
		while Index_nums2 >= 0{
			nums1[Index_nums_total] = nums2[Index_nums2]
			Index_nums_total -= 1
			Index_nums2 -= 1
		}

	}
}