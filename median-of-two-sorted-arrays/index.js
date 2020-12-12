/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function (nums1, nums2) {
    var helper = {
        isEven: function (data) {
            return Array.isArray(data) ? data.length % 2 === 0 : data % 2  === 0;
        },
        getMiddleIndex: function (data) {
            return Array.isArray(data) ? Math.floor(data.length / 2) : Math.floor(data / 2);
        },
        getMiddleValueFromArray: function (targetArr) {
            var middleIndex2 = this.getMiddleIndex(targetArr);
            return this.isEven(targetArr) ? (targetArr[middleIndex2-1] + targetArr[middleIndex2])/2 : targetArr[middleIndex2];
        }
    };

    var size1 = nums1.length;
    var size2 = nums2.length;
    
    /** compare array size if nums1 is less than nums2 then flip the parameter order to ensure first array is smaller than second array */
    if (size1 > size2) {
        return findMedianSortedArrays(nums2, nums1);
    }

    /** if nums1 empty use nums2 to get mediem number */
    if (size1 === 0) {
        return helper.getMiddleValueFromArray(nums2);
    }
    
    /** find middle number of the combine array */
    var m1 = helper.getMiddleIndex(size1);
    var m2 = helper.getMiddleIndex(size2);

    var k = helper.getMiddleIndex(size1 + size2);

    var upper = nums1[m1];
    var lower = nums2[m2];
    /** move m2 if less than m1 to find lower value from seconds parameters */

    // && m1 <= size1 && m2 > 0
    //  &&  m1 < size1 && m2 > 0
    while (upper < lower) {
        m2 = m2 - 1;
        if (0 <= m2) {
            lower = nums2[m2];
        }
        m1 = m1 + 1;
        if (size1-1 >= m1) {
            upper = nums1[m1];
        }
        
        if (size1-1 < m1 && m2 === 0) {
            break;
        }
    }
    
    console.log('while k value:', k, m2, upper ,lower);
    
    console.log(m1, m2, nums1, nums2 , upper, lower);

    return  (upper+lower) / 2;
};

module.exports = findMedianSortedArrays;

