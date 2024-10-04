<?php

// Procedure to sort the array through the `Insertion Sort` algorithm
function insertionSort(&$arr){// we need to pass the array by reference to affect its order
    for($i = 0; $i < count($arr); $i++){
    $key = $arr[$i];
    $j = $i-1;
    while($j >= 0 and $arr[$j] > $key){
        $arr[$j + 1] = $arr[$j];
        $j = $j - 1;
    }
    $arr[$j + 1] = $key;
    }
}

// Procedure to show the array elements
function showArray($arr){
    for($k = 0; $k<count($arr); $k++){
    echo $arr[$k] . " ";
    }
    echo "\n";
}

$A = array(3,7,2,8);

echo "The not-sorted array is: \n";
    
// show the array before being sorted by calling call the `showArray` procedure
showArray($A);
    
// call the `insertionSort` algorithm procedure
insertionSort($A);
    
echo "The sorted array is: \n";
// show the sorted array
showArray($A);

?>