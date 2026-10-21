import itertools
import subprocess

count = 0
for spec in ("d", "i", "u", "x", "X"):
    values = (0, 1, 42, 2147483647)
    if spec in ("d", "i"):
        values += (-1, -42, -2147483648)
    else:
        values += (4294967295,)
    for flag, width, precision, value in itertools.product(
            ("", "-", "0"), ("", "1", "12"), ("", ".0", ".5"), values):
        fmt = "%" + flag + width + precision + spec
        results = [subprocess.run(
            ["./ft_printf_test", mode, fmt, str(value), "unused"],
            capture_output=True, check=True, timeout=5)
            for mode in ("custom", "system")]
        assert (results[0].stdout, results[0].stderr) == (
            results[1].stdout, results[1].stderr), (fmt, value, results)
        count += 1
print(f"{count} numeric cases match system printf bytes and return values")
