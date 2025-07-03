# Client Side Again

link to the chall - [link](https://play.picoctf.org/practice/challenge/69?difficulty=2&page=1&search=client&solved=0)

---

[Uploading vid.webm…]()

---
on openning the given site, there was an array with jumbled flag, and a obfuscated verify function.

```js
var _0x5a46 = ['f49bf}', '_again_e', 'this', 'Password Verified', 'Incorrect password', 'getElementById', 'value', 'substring', 'picoCTF{', 'not_this'];
(function (_0x4bd822, _0x2bd6f7) {
    var _0xb4bdb3 = function (_0x1d68f6) {
        while (--_0x1d68f6) {
            _0x4bd822['push'](_0x4bd822['shift']());
        }
    };
    _0xb4bdb3(++_0x2bd6f7);
}(_0x5a46, 0x1b3));
var _0x4b5b = function (_0x2d8f05, _0x4b81bb) {
    _0x2d8f05 = _0x2d8f05 - 0x0;
    var _0x4d74cb = _0x5a46[_0x2d8f05];
    return _0x4d74cb;
};
function verify() {
    checkpass = document[_0x4b5b('0x0')]('pass')[_0x4b5b('0x1')];
    split = 0x4;
    if (checkpass[_0x4b5b('0x2')](0x0, split * 0x2) == _0x4b5b('0x3')) {
        if (checkpass[_0x4b5b('0x2')](0x7, 0x9) == '{n') {
            if (checkpass[_0x4b5b('0x2')](split * 0x2, split * 0x2 * 0x2) == _0x4b5b('0x4')) {
                if (checkpass[_0x4b5b('0x2')](0x3, 0x6) == 'oCT') {
                    if (checkpass[_0x4b5b('0x2')](split * 0x3 * 0x2, split * 0x4 * 0x2) == _0x4b5b('0x5')) {
                        if (checkpass['substring'](0x6, 0xb) == 'F{not') {
                            if (checkpass[_0x4b5b('0x2')](split * 0x2 * 0x2, split * 0x3 * 0x2) == _0x4b5b('0x6')) {
                                if (checkpass[_0x4b5b('0x2')](0xc, 0x10) == _0x4b5b('0x7')) {
                                    alert(_0x4b5b('0x8'));
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        alert(_0x4b5b('0x9'));
    }
}
```

I wrote a deobfuscated js for it
```js
var _0x5a46 = ['f49bf}', '_again_e', 'this', 'Password Verified', 'Incorrect password', 'getElementById', 'value', 'substring', 'picoCTF{', 'not_this'];
(function (_0x4bd822, _0x2bd6f7) {
    var _0xb4bdb3 = function (_0x1d68f6) {
        while (--_0x1d68f6) {
            _0x4bd822['push'](_0x4bd822['shift']());
        }
    };
    _0xb4bdb3(++_0x2bd6f7);
}(_0x5a46, 0x1b3));
var _0x4b5b = function (_0x2d8f05, _0x4b81bb) {
    _0x2d8f05 = _0x2d8f05 - 0x0;
    var _0x4d74cb = _0x5a46[_0x2d8f05];
    return _0x4d74cb;
};

function verify() {
    checkpass = document[getElementById]('pass')['value'];
    split = 4;
    if (checkpass['substring'](0, 8) == "picoctf{") {
        if (checkpass['substring'](7, 9) == '{n') {
            if (checkpass['substring'](8, 16) == 'not_this') {
                if (checkpass['substring'](3, 6) == 'oCT') {
                    if (checkpass['substring'](24, 32) == 'f49bf}') {
                        if (checkpass['substring'](6, 11) == 'F{not') {
                            if (checkpass['substring'](16, 24) == '_again_e') {
                                if (checkpass['substring'](12, 16) == 'this') {
                                    alert('Password Verified');
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        alert('Incorrect password');
    }
}
```

flag - `picoCTF{not_this_again_ef49bf}}`
