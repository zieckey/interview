<?php

function resolve($input)
{
    return 0;
}


//main
$input = array(
    "3\n1,3,2\n2,4,4\n6,7,5\n", //The giving example
    "1\n1,2,1\n",
    "2\n1,2,1\n2,3,2",
    "3\n1,2,1\n2,3,2\n3,6,1",
    "4\n1,2,1\n2,3,2\n3,6,1\n5,8,2",
    "5\n1,2,1\n2,3,2\n3,6,1\n5,8,2\n7,9,1",
    "1\n0,1,1",
    "2\n0,1,1\n2,4,3",
    "3\n0,1,1\n2,4,3\n3,5,1",
    "4\n0,1,1\n2,4,3\n3,5,1\n5,6,1",
    "5\n0,1,1\n2,4,3\n3,5,1\n5,6,1\n6,8,3",
    //TODO please add more test case here
);

$expectedSteps = array(
            25, 4, 7, 10, 14, 15, 3, 12, 13, 14, 20);

$passed = true;
assert(count($input) == count($expectedSteps));
for ($i = 0; $i < count($input); ++$i)
{
    assert(resolve($input[$i]) == $expectedSteps[$i]);
    if (resolve($input[$i]) != $expectedSteps[$i])
    {
        $passed = false;
    }
}

if ($passed)
{
    echo "PASSED!\n";
}
else
{
    echo "FAILED!\n";
}
