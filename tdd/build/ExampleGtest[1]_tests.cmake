add_test([=[testFixtures.test3]=]  /run/media/pedromn35/disk2-home/projects/cpp-training-before-rest-hlf/tdd/build/ExampleGtest [==[--gtest_filter=testFixtures.test3]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[testFixtures.test3]=]  PROPERTIES WORKING_DIRECTORY /run/media/pedromn35/disk2-home/projects/cpp-training-before-rest-hlf/tdd/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[exampleTest.test1]=]  /run/media/pedromn35/disk2-home/projects/cpp-training-before-rest-hlf/tdd/build/ExampleGtest [==[--gtest_filter=exampleTest.test1]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[exampleTest.test1]=]  PROPERTIES WORKING_DIRECTORY /run/media/pedromn35/disk2-home/projects/cpp-training-before-rest-hlf/tdd/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[exampleTest.test2]=]  /run/media/pedromn35/disk2-home/projects/cpp-training-before-rest-hlf/tdd/build/ExampleGtest [==[--gtest_filter=exampleTest.test2]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[exampleTest.test2]=]  PROPERTIES WORKING_DIRECTORY /run/media/pedromn35/disk2-home/projects/cpp-training-before-rest-hlf/tdd/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  ExampleGtest_TESTS testFixtures.test3 exampleTest.test1 exampleTest.test2)
