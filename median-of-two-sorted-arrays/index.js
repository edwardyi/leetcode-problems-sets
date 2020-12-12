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

    /** total length from two array */
    var totalLength = size1 + size2;

    /** _start_nums1 */
    var _start_nums1 = 0; 
    var _end_nums1 = size1;
    var l1, r1, l2, r2;
    while (_start_nums1 < _end_nums1) {
        /** ensure middle1 is getting more than 1 middle2 */
        var middle1 = Math.ceil(_start_nums1 + _end_nums1 / 2);
        var middle2 = Math.floor((totalLength + 1) / 2) - middle1;

        console.log('middle and size:', size1, middle1, size2, middle2);
        console.log('while loop:', totalLength, nums1, nums2 , _start_nums1, _end_nums1);

        l1 = middle1 === 0 ? 0 : nums1[middle1-1];
        r1 = middle1 === size1 ? nums1[size1-1] : nums1[middle1];
        l2 = middle2 === 0 ? 0 : nums2[middle2-1];
        r2 = middle2 === size2 ? nums2[size2-1] : nums2[middle2];
        
        console.log('l r values', l1, l2, r1, r2);

        /** update nums1 start and end */
        if (l1 > r2) {
            _end_nums1 = middle1 - 1;
        } else if (l2 > r1) {
            _start_nums1 = middle1 + 1;
        } else {
            console.log('break: ', l1, r1, r2, l2);
            break;
        }
    }

    var upper = Math.max(l1, l2);
    var lower = Math.min(r1, r2);

    /** change upper if greater than nums2 array */
    if (upper > nums2[size2-1]) {
        upper = nums2[size2-1];
    }

    console.log('testing upper and lower', upper, lower, Math.min(upper, lower), upper+lower);
    
    console.log('middle1 boundary:', _start_nums1, _end_nums1, middle1, middle2, nums1, nums2);

    return helper.isEven(totalLength) ? (upper + lower)/2 : Math.min(upper,lower);
    
};

module.exports = findMedianSortedArrays;