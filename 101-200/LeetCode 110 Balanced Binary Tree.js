/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */

function getMaxValue(a,b){
	if (a>=b){
		return a;
	}
	return b;
}
function getHeight(root){
	if (root.left === null && root.right === null){
		return 1;
	}
	var maxHeightValue = 0;
	if (root.left !== null){
		maxHeightValue = getMaxValue(maxHeightValue, getHeight(root.left)+1);
	}
	if (root.right !== null){
		maxHeightValue = getMaxValue(maxHeightValue, getHeight(root.right)+1);
	}
	return maxHeightValue;
}
function isBalancedNode(root){
	if (root === null || (root.left===null && root.right===null)){
		return true;
	}
	if (root.left !== null && root.right === null){
		if (getHeight(root.left) <= 1 && isBalancedNode(root.left)){
			return true;
		}
		else{
			return false;
		}
	}
	if (root.left === null && root.right !== null){
		console.log(getHeight(root.right))
		if (getHeight(root.right) <= 1 && isBalancedNode(root.right)){
			return true;
		}
		else{
			return false;
		}
	}
	var Dist=Math.abs(getHeight(root.left) - getHeight(root.right));
	if (isBalancedNode(root.left) && isBalancedNode(root.right) && Dist <=1){
		return true;
	}
	else{
		return false;
	}
}
var isBalanced = function(root) {
	return isBalancedNode(root);
}