# Quick n Dirty Implementation of Tomohiko Sakamoto's Algorithm

## Overview

This repository contains a simple implementation of Tomohiko Sakamoto's Algorithm for finding the day of the week using the C language. The code was originally written in the early 1990s and was published on GitHub around 2019 as a part of an experiment to explore GitHub's features.

## Disclaimer

The original code was not intended to be production-ready. It was created to quickly achieve a task, hence the title.

## Recent Updates

While randomly checking my GitHub account on 25 May 2024, I came across this repository and noticed it lacked basic validations. Specifically:
- The code did not handle invalid dates such as days exceeding the number of days in a month or months and years beyond typical limits.
- There was no input validation to ensure the entered values were within the expected range.

To address these issues, I have revised the code with basic input validation and published it in a separate file named `validated_dow.c`.

## Files

- `dow.c`: The original implementation of the algorithm.
- `validated_dow.c`: The revised implementation with added input validations.

## License

This project is licensed under the MIT License.

## Contributions

This project was an experiment and is not maintained. Just take it as it is. Thanks.

## Author

Venkatarangan Thirumalai [venkatarangan.com](https://venkatarangan.com)
