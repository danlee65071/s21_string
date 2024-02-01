#include "tests.h"

void case_test(Suite *s, int *fail) {
  SRunner *runner = srunner_create(s);
  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  *fail = srunner_ntests_failed(runner);
  srunner_free(runner);
}

int main() {
  int result[1] = {0};
  int fail = 0;

  case_test(t_memchr(), result);

  for (int i = 0; i < 1; i++) {
    if (result[i] != 0) {
      fail = 1;
    }
  }
  return fail;
}