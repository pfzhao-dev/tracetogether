#include <stdlib.h>
#include <stdio.h>
#include <math.h>

static int predict(float features[11]) {

    static int classes[2];
        
    if (features[5] <= -73.5) {
        if (features[5] <= -80.0) {
            return 0;
        }

        if (features[10] <= 6236.0) {
            if (features[7] <= 124.5) {
                if (features[10] <= 5770.5) {
                    classes[0] = 596; 
                    classes[1] = 0; 
                } else {
                    if (features[5] <= -76.5) {
                        if (features[2] <= 11150.5) {
                            if (features[4] <= 8423.0) {
                                if (features[8] <= 15706.5) {
                                    if (features[1] <= 97.5) {
                                        if (features[3] <= 3046.5) {
                                            classes[0] = 0; 
                                            classes[1] = 2; 
                                        } else {
                                            if (features[10] <= 6066.0) {
                                                if (features[10] <= 6032.5) {
                                                    classes[0] = 2; 
                                                    classes[1] = 0; 
                                                } else {
                                                    classes[0] = 0; 
                                                    classes[1] = 1; 
                                                }
                                            } else {
                                                classes[0] = 26; 
                                                classes[1] = 0; 
                                            }
                                        }
                                    } else {
                                        classes[0] = 205; 
                                        classes[1] = 0; 
                                    }
                                } else {
                                    if (features[5] <= -85.5) {
                                        classes[0] = 0; 
                                        classes[1] = 1; 
                                    } else {
                                        classes[0] = 1; 
                                        classes[1] = 0; 
                                    }
                                }
                            } else {
                                classes[0] = 0; 
                                classes[1] = 2; 
                            }
                        } else {
                            if (features[3] <= 3441.5) {
                                if (features[6] <= 20627.5) {
                                    if (features[2] <= 11345.5) {
                                        classes[0] = 0; 
                                        classes[1] = 1; 
                                    } else {
                                        classes[0] = 7; 
                                        classes[1] = 0; 
                                    }
                                } else {
                                    classes[0] = 0; 
                                    classes[1] = 9; 
                                }
                            } else {
                                classes[0] = 17; 
                                classes[1] = 0; 
                            }
                        }
                    } else {
                        if (features[4] <= 6320.0) {
                            classes[0] = 23; 
                            classes[1] = 0; 
                        } else {
                            if (features[0] <= 866111.5) {
                                if (features[0] <= 15.0) {
                                    classes[0] = 2; 
                                    classes[1] = 0; 
                                } else {
                                    if (features[3] <= 2783.5) {
                                        classes[0] = 1; 
                                        classes[1] = 0; 
                                    } else {
                                        if (features[10] <= 6227.5) {
                                            classes[0] = 0; 
                                            classes[1] = 17; 
                                        } else {
                                            classes[0] = 1; 
                                            classes[1] = 0; 
                                        }
                                    }
                                }
                            } else {
                                classes[0] = 3; 
                                classes[1] = 0; 
                            }
                        }
                    }
                }
            } else {
                if (features[9] <= 3610.5) {
                    classes[0] = 0; 
                    classes[1] = 5; 
                } else {
                    classes[0] = 2; 
                    classes[1] = 0; 
                }
            }
        } else {
            if (features[4] <= 5890.0) {
                if (features[3] <= 3185.0) {
                    if (features[5] <= -76.5) {
                        if (features[1] <= 94.5) {
                            classes[0] = 0; 
                            classes[1] = 1; 
                        } else {
                            classes[0] = 37; 
                            classes[1] = 0; 
                        }
                    } else {
                        classes[0] = 0; 
                        classes[1] = 3; 
                    }
                } else {
                    classes[0] = 417; 
                    classes[1] = 0; 
                }
            } else {
                if (features[5] <= -84.5) {
                    if (features[10] <= 8317.5) {
                        if (features[10] <= 7451.5) {
                            if (features[4] <= 8218.0) {
                                if (features[4] <= 7466.0) {
                                    if (features[0] <= 41.5) {
                                        if (features[2] <= 8375.5) {
                                            classes[0] = 2; 
                                            classes[1] = 0; 
                                        } else {
                                            classes[0] = 0; 
                                            classes[1] = 8; 
                                        }
                                    } else {
                                        if (features[6] <= 157.5) {
                                            classes[0] = 0; 
                                            classes[1] = 3; 
                                        } else {
                                            if (features[7] <= 93.5) {
                                                if (features[9] <= 3497.5) {
                                                    if (features[3] <= 3358.5) {
                                                        if (features[2] <= 5569.5) {
                                                            classes[0] = 0; 
                                                            classes[1] = 1; 
                                                        } else {
                                                            classes[0] = 4; 
                                                            classes[1] = 0; 
                                                        }
                                                    } else {
                                                        classes[0] = 0; 
                                                        classes[1] = 8; 
                                                    }
                                                } else {
                                                    classes[0] = 6; 
                                                    classes[1] = 0; 
                                                }
                                            } else {
                                                if (features[3] <= 3123.0) {
                                                    if (features[7] <= 100.5) {
                                                        classes[0] = 1; 
                                                        classes[1] = 0; 
                                                    } else {
                                                        classes[0] = 0; 
                                                        classes[1] = 4; 
                                                    }
                                                } else {
                                                    if (features[4] <= 5950.0) {
                                                        classes[0] = 0; 
                                                        classes[1] = 2; 
                                                    } else {
                                                        if (features[9] <= 3060.0) {
                                                            classes[0] = 0; 
                                                            classes[1] = 2; 
                                                        } else {
                                                            if (features[7] <= 150.0) {
                                                                if (features[4] <= 7404.0) {
                                                                    if (features[4] <= 7119.5) {
                                                                        if (features[6] <= 9424.5) {
                                                                            if (features[10] <= 7396.0) {
                                                                                if (features[0] <= 1379712.0) {
                                                                                    classes[0] = 38; 
                                                                                    classes[1] = 0; 
                                                                                } else {
                                                                                    classes[0] = 0; 
                                                                                    classes[1] = 1; 
                                                                                }
                                                                            } else {
                                                                                classes[0] = 0; 
                                                                                classes[1] = 1; 
                                                                            }
                                                                        } else {
                                                                            if (features[3] <= 3509.5) {
                                                                                if (features[3] <= 3327.5) {
                                                                                    if (features[9] <= 3369.5) {
                                                                                        classes[0] = 9; 
                                                                                        classes[1] = 0; 
                                                                                    } else {
                                                                                        classes[0] = 0; 
                                                                                        classes[1] = 1; 
                                                                                    }
                                                                                } else {
                                                                                    classes[0] = 0; 
                                                                                    classes[1] = 11; 
                                                                                }
                                                                            } else {
                                                                                if (features[6] <= 326848.0) {
                                                                                    if (features[8] <= 7828.5) {
                                                                                        classes[0] = 0; 
                                                                                        classes[1] = 3; 
                                                                                    } else {
                                                                                        classes[0] = 1; 
                                                                                        classes[1] = 0; 
                                                                                    }
                                                                                } else {
                                                                                    if (features[2] <= 21741.0) {
                                                                                        classes[0] = 34; 
                                                                                        classes[1] = 0; 
                                                                                    } else {
                                                                                        if (features[7] <= 100.5) {
                                                                                            classes[0] = 1; 
                                                                                            classes[1] = 0; 
                                                                                        } else {
                                                                                            classes[0] = 0; 
                                                                                            classes[1] = 1; 
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    } else {
                                                                        classes[0] = 43; 
                                                                        classes[1] = 0; 
                                                                    }
                                                                } else {
                                                                    if (features[2] <= 7277.5) {
                                                                        classes[0] = 0; 
                                                                        classes[1] = 3; 
                                                                    } else {
                                                                        if (features[9] <= 3334.0) {
                                                                            classes[0] = 4; 
                                                                            classes[1] = 0; 
                                                                        } else {
                                                                            classes[0] = 0; 
                                                                            classes[1] = 1; 
                                                                        }
                                                                    }
                                                                }
                                                            } else {
                                                                classes[0] = 0; 
                                                                classes[1] = 2; 
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[2] <= 13299.0) {
                                        if (features[1] <= 128.5) {
                                            classes[0] = 87; 
                                            classes[1] = 0; 
                                        } else {
                                            if (features[4] <= 8076.5) {
                                                classes[0] = 2; 
                                                classes[1] = 0; 
                                            } else {
                                                classes[0] = 0; 
                                                classes[1] = 1; 
                                            }
                                        }
                                    } else {
                                        if (features[5] <= -89.0) {
                                            classes[0] = 5; 
                                            classes[1] = 0; 
                                        } else {
                                            classes[0] = 0; 
                                            classes[1] = 3; 
                                        }
                                    }
                                }
                            } else {
                                if (features[10] <= 7252.0) {
                                    classes[0] = 0; 
                                    classes[1] = 7; 
                                } else {
                                    classes[0] = 1; 
                                    classes[1] = 0; 
                                }
                            }
                        } else {
                            if (features[7] <= 82.5) {
                                classes[0] = 0; 
                                classes[1] = 1; 
                            } else {
                                if (features[4] <= 7219.0) {
                                    if (features[4] <= 7075.0) {
                                        if (features[3] <= 3106.0) {
                                            classes[0] = 0; 
                                            classes[1] = 2; 
                                        } else {
                                            if (features[10] <= 7633.0) {
                                                if (features[6] <= 32484.5) {
                                                    classes[0] = 0; 
                                                    classes[1] = 1; 
                                                } else {
                                                    classes[0] = 4; 
                                                    classes[1] = 0; 
                                                }
                                            } else {
                                                classes[0] = 64; 
                                                classes[1] = 0; 
                                            }
                                        }
                                    } else {
                                        if (features[5] <= -90.0) {
                                            classes[0] = 0; 
                                            classes[1] = 4; 
                                        } else {
                                            classes[0] = 2; 
                                            classes[1] = 0; 
                                        }
                                    }
                                } else {
                                    classes[0] = 88; 
                                    classes[1] = 0; 
                                }
                            }
                        }
                    } else {
                        if (features[3] <= 3336.5) {
                            classes[0] = 14; 
                            classes[1] = 0; 
                        } else {
                            classes[0] = 0; 
                            classes[1] = 23; 
                        }
                    }
                } else {
                    if (features[10] <= 8153.0) {
                        if (features[10] <= 7797.5) {
                            if (features[3] <= 3547.0) {
                                if (features[6] <= 838.0) {
                                    if (features[9] <= 2929.5) {
                                        if (features[0] <= 542.0) {
                                            classes[0] = 5; 
                                            classes[1] = 0; 
                                        } else {
                                            classes[0] = 0; 
                                            classes[1] = 3; 
                                        }
                                    } else {
                                        if (features[4] <= 6664.0) {
                                            if (features[4] <= 6552.0) {
                                                if (features[2] <= 1871.0) {
                                                    if (features[9] <= 3144.5) {
                                                        classes[0] = 0; 
                                                        classes[1] = 1; 
                                                    } else {
                                                        classes[0] = 2; 
                                                        classes[1] = 0; 
                                                    }
                                                } else {
                                                    if (features[9] <= 3698.0) {
                                                        classes[0] = 0; 
                                                        classes[1] = 23; 
                                                    } else {
                                                        classes[0] = 1; 
                                                        classes[1] = 0; 
                                                    }
                                                }
                                            } else {
                                                classes[0] = 8; 
                                                classes[1] = 0; 
                                            }
                                        } else {
                                            if (features[10] <= 6440.0) {
                                                classes[0] = 1; 
                                                classes[1] = 0; 
                                            } else {
                                                if (features[10] <= 7711.5) {
                                                    if (features[0] <= 225952.0) {
                                                        classes[0] = 0; 
                                                        classes[1] = 71; 
                                                    } else {
                                                        if (features[3] <= 3232.5) {
                                                            classes[0] = 0; 
                                                            classes[1] = 3; 
                                                        } else {
                                                            classes[0] = 1; 
                                                            classes[1] = 0; 
                                                        }
                                                    }
                                                } else {
                                                    if (features[6] <= 123.0) {
                                                        classes[0] = 1; 
                                                        classes[1] = 0; 
                                                    } else {
                                                        classes[0] = 0; 
                                                        classes[1] = 1; 
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[4] <= 7345.5) {
                                        if (features[0] <= 405.5) {
                                            if (features[2] <= 14870.0) {
                                                classes[0] = 0; 
                                                classes[1] = 19; 
                                            } else {
                                                if (features[8] <= 8649.0) {
                                                    classes[0] = 4; 
                                                    classes[1] = 0; 
                                                } else {
                                                    classes[0] = 0; 
                                                    classes[1] = 4; 
                                                }
                                            }
                                        } else {
                                            if (features[3] <= 3342.5) {
                                                if (features[0] <= 898118.0) {
                                                    if (features[5] <= -75.5) {
                                                        if (features[3] <= 3104.5) {
                                                            if (features[9] <= 2691.5) {
                                                                classes[0] = 7; 
                                                                classes[1] = 0; 
                                                            } else {
                                                                if (features[4] <= 6020.0) {
                                                                    if (features[9] <= 3028.0) {
                                                                        classes[0] = 0; 
                                                                        classes[1] = 1; 
                                                                    } else {
                                                                        classes[0] = 4; 
                                                                        classes[1] = 0; 
                                                                    }
                                                                } else {
                                                                    classes[0] = 0; 
                                                                    classes[1] = 10; 
                                                                }
                                                            }
                                                        } else {
                                                            if (features[1] <= 96.5) {
                                                                if (features[5] <= -81.0) {
                                                                    if (features[7] <= 110.5) {
                                                                        classes[0] = 10; 
                                                                        classes[1] = 0; 
                                                                    } else {
                                                                        classes[0] = 0; 
                                                                        classes[1] = 1; 
                                                                    }
                                                                } else {
                                                                    if (features[3] <= 3284.5) {
                                                                        if (features[7] <= 100.0) {
                                                                            classes[0] = 0; 
                                                                            classes[1] = 1; 
                                                                        } else {
                                                                            classes[0] = 2; 
                                                                            classes[1] = 0; 
                                                                        }
                                                                    } else {
                                                                        classes[0] = 0; 
                                                                        classes[1] = 6; 
                                                                    }
                                                                }
                                                            } else {
                                                                if (features[10] <= 7358.5) {
                                                                    if (features[1] <= 124.0) {
                                                                        if (features[9] <= 2918.0) {
                                                                            classes[0] = 0; 
                                                                            classes[1] = 1; 
                                                                        } else {
                                                                            if (features[0] <= 739.5) {
                                                                                if (features[7] <= 114.0) {
                                                                                    classes[0] = 1; 
                                                                                    classes[1] = 0; 
                                                                                } else {
                                                                                    classes[0] = 0; 
                                                                                    classes[1] = 1; 
                                                                                }
                                                                            } else {
                                                                                classes[0] = 64; 
                                                                                classes[1] = 0; 
                                                                            }
                                                                        }
                                                                    } else {
                                                                        if (features[6] <= 5440.0) {
                                                                            classes[0] = 1; 
                                                                            classes[1] = 0; 
                                                                        } else {
                                                                            classes[0] = 0; 
                                                                            classes[1] = 2; 
                                                                        }
                                                                    }
                                                                } else {
                                                                    if (features[10] <= 7432.0) {
                                                                        classes[0] = 0; 
                                                                        classes[1] = 3; 
                                                                    } else {
                                                                        if (features[4] <= 7059.5) {
                                                                            if (features[1] <= 98.5) {
                                                                                if (features[10] <= 7573.0) {
                                                                                    classes[0] = 1; 
                                                                                    classes[1] = 0; 
                                                                                } else {
                                                                                    classes[0] = 0; 
                                                                                    classes[1] = 1; 
                                                                                }
                                                                            } else {
                                                                                classes[0] = 11; 
                                                                                classes[1] = 0; 
                                                                            }
                                                                        } else {
                                                                            classes[0] = 0; 
                                                                            classes[1] = 2; 
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        if (features[10] <= 6520.0) {
                                                            classes[0] = 7; 
                                                            classes[1] = 0; 
                                                        } else {
                                                            if (features[7] <= 96.0) {
                                                                classes[0] = 6; 
                                                                classes[1] = 0; 
                                                            } else {
                                                                if (features[0] <= 301168.0) {
                                                                    if (features[4] <= 6552.0) {
                                                                        if (features[3] <= 3139.5) {
                                                                            classes[0] = 0; 
                                                                            classes[1] = 2; 
                                                                        } else {
                                                                            classes[0] = 3; 
                                                                            classes[1] = 0; 
                                                                        }
                                                                    } else {
                                                                        if (features[9] <= 3447.5) {
                                                                            if (features[4] <= 7276.0) {
                                                                                classes[0] = 0; 
                                                                                classes[1] = 16; 
                                                                            } else {
                                                                                if (features[2] <= 8108.5) {
                                                                                    classes[0] = 0; 
                                                                                    classes[1] = 1; 
                                                                                } else {
                                                                                    classes[0] = 1; 
                                                                                    classes[1] = 0; 
                                                                                }
                                                                            }
                                                                        } else {
                                                                            classes[0] = 1; 
                                                                            classes[1] = 0; 
                                                                        }
                                                                    }
                                                                } else {
                                                                    if (features[7] <= 101.5) {
                                                                        classes[0] = 0; 
                                                                        classes[1] = 2; 
                                                                    } else {
                                                                        classes[0] = 5; 
                                                                        classes[1] = 0; 
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    classes[0] = 0; 
                                                    classes[1] = 7; 
                                                }
                                            } else {
                                                if (features[0] <= 9463.0) {
                                                    if (features[3] <= 3409.5) {
                                                        if (features[9] <= 3240.0) {
                                                            classes[0] = 6; 
                                                            classes[1] = 0; 
                                                        } else {
                                                            if (features[9] <= 3496.0) {
                                                                classes[0] = 0; 
                                                                classes[1] = 14; 
                                                            } else {
                                                                if (features[4] <= 7081.5) {
                                                                    classes[0] = 5; 
                                                                    classes[1] = 0; 
                                                                } else {
                                                                    classes[0] = 0; 
                                                                    classes[1] = 2; 
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        classes[0] = 24; 
                                                        classes[1] = 0; 
                                                    }
                                                } else {
                                                    if (features[5] <= -78.5) {
                                                        if (features[3] <= 3420.0) {
                                                            classes[0] = 10; 
                                                            classes[1] = 0; 
                                                        } else {
                                                            if (features[0] <= 1014623.5) {
                                                                if (features[6] <= 1144.0) {
                                                                    classes[0] = 1; 
                                                                    classes[1] = 0; 
                                                                } else {
                                                                    classes[0] = 0; 
                                                                    classes[1] = 11; 
                                                                }
                                                            } else {
                                                                if (features[2] <= 2787.0) {
                                                                    classes[0] = 0; 
                                                                    classes[1] = 2; 
                                                                } else {
                                                                    classes[0] = 7; 
                                                                    classes[1] = 0; 
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        if (features[6] <= 5633728.0) {
                                                            if (features[9] <= 3698.5) {
                                                                classes[0] = 0; 
                                                                classes[1] = 39; 
                                                            } else {
                                                                if (features[10] <= 6675.0) {
                                                                    classes[0] = 0; 
                                                                    classes[1] = 5; 
                                                                } else {
                                                                    classes[0] = 1; 
                                                                    classes[1] = 0; 
                                                                }
                                                            }
                                                        } else {
                                                            if (features[0] <= 697952.0) {
                                                                classes[0] = 0; 
                                                                classes[1] = 2; 
                                                            } else {
                                                                classes[0] = 5; 
                                                                classes[1] = 0; 
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[10] <= 6814.5) {
                                            if (features[3] <= 3297.0) {
                                                if (features[9] <= 3086.0) {
                                                    classes[0] = 0; 
                                                    classes[1] = 4; 
                                                } else {
                                                    classes[0] = 31; 
                                                    classes[1] = 0; 
                                                }
                                            } else {
                                                if (features[0] <= 632191.5) {
                                                    if (features[10] <= 6766.5) {
                                                        if (features[1] <= 122.5) {
                                                            classes[0] = 0; 
                                                            classes[1] = 40; 
                                                        } else {
                                                            if (features[8] <= 2173.5) {
                                                                classes[0] = 0; 
                                                                classes[1] = 1; 
                                                            } else {
                                                                classes[0] = 1; 
                                                                classes[1] = 0; 
                                                            }
                                                        }
                                                    } else {
                                                        if (features[2] <= 7773.0) {
                                                            classes[0] = 2; 
                                                            classes[1] = 0; 
                                                        } else {
                                                            classes[0] = 0; 
                                                            classes[1] = 1; 
                                                        }
                                                    }
                                                } else {
                                                    if (features[5] <= -75.0) {
                                                        classes[0] = 4; 
                                                        classes[1] = 0; 
                                                    } else {
                                                        classes[0] = 0; 
                                                        classes[1] = 1; 
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[0] <= 4733.0) {
                                                classes[0] = 0; 
                                                classes[1] = 66; 
                                            } else {
                                                if (features[10] <= 7016.0) {
                                                    if (features[9] <= 3306.5) {
                                                        classes[0] = 0; 
                                                        classes[1] = 5; 
                                                    } else {
                                                        classes[0] = 7; 
                                                        classes[1] = 0; 
                                                    }
                                                } else {
                                                    classes[0] = 0; 
                                                    classes[1] = 22; 
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[10] <= 6406.5) {
                                    if (features[6] <= 999263.5) {
                                        classes[0] = 0; 
                                        classes[1] = 26; 
                                    } else {
                                        classes[0] = 2; 
                                        classes[1] = 0; 
                                    }
                                } else {
                                    if (features[4] <= 8323.0) {
                                        if (features[0] <= 296192.0) {
                                            if (features[6] <= 206.5) {
                                                classes[0] = 0; 
                                                classes[1] = 1; 
                                            } else {
                                                if (features[8] <= 1824.0) {
                                                    if (features[3] <= 3574.0) {
                                                        classes[0] = 4; 
                                                        classes[1] = 0; 
                                                    } else {
                                                        classes[0] = 0; 
                                                        classes[1] = 2; 
                                                    }
                                                } else {
                                                    if (features[6] <= 10384.0) {
                                                        if (features[6] <= 9556.0) {
                                                            if (features[10] <= 6442.0) {
                                                                classes[0] = 0; 
                                                                classes[1] = 1; 
                                                            } else {
                                                                if (features[1] <= 112.5) {
                                                                    classes[0] = 23; 
                                                                    classes[1] = 0; 
                                                                } else {
                                                                    if (features[1] <= 117.0) {
                                                                        classes[0] = 0; 
                                                                        classes[1] = 1; 
                                                                    } else {
                                                                        classes[0] = 3; 
                                                                        classes[1] = 0; 
                                                                    }
                                                                }
                                                            }
                                                        } else {
                                                            classes[0] = 0; 
                                                            classes[1] = 1; 
                                                        }
                                                    } else {
                                                        classes[0] = 66; 
                                                        classes[1] = 0; 
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[5] <= -74.5) {
                                                if (features[8] <= 4159.0) {
                                                    if (features[9] <= 3474.5) {
                                                        classes[0] = 7; 
                                                        classes[1] = 0; 
                                                    } else {
                                                        classes[0] = 0; 
                                                        classes[1] = 9; 
                                                    }
                                                } else {
                                                    if (features[9] <= 3467.5) {
                                                        if (features[8] <= 8032.5) {
                                                            classes[0] = 3; 
                                                            classes[1] = 0; 
                                                        } else {
                                                            classes[0] = 0; 
                                                            classes[1] = 4; 
                                                        }
                                                    } else {
                                                        classes[0] = 21; 
                                                        classes[1] = 0; 
                                                    }
                                                }
                                            } else {
                                                classes[0] = 0; 
                                                classes[1] = 5; 
                                            }
                                        }
                                    } else {
                                        classes[0] = 0; 
                                        classes[1] = 7; 
                                    }
                                }
                            }
                        } else {
                            if (features[6] <= 110.0) {
                                if (features[3] <= 3103.0) {
                                    if (features[3] <= 2855.0) {
                                        classes[0] = 1; 
                                        classes[1] = 0; 
                                    } else {
                                        classes[0] = 0; 
                                        classes[1] = 2; 
                                    }
                                } else {
                                    if (features[6] <= 27.0) {
                                        classes[0] = 61; 
                                        classes[1] = 0; 
                                    } else {
                                        if (features[0] <= 139858.0) {
                                            if (features[9] <= 3579.0) {
                                                classes[0] = 1; 
                                                classes[1] = 0; 
                                            } else {
                                                classes[0] = 0; 
                                                classes[1] = 3; 
                                            }
                                        } else {
                                            classes[0] = 15; 
                                            classes[1] = 0; 
                                        }
                                    }
                                }
                            } else {
                                if (features[6] <= 15716.0) {
                                    if (features[10] <= 7891.5) {
                                        if (features[3] <= 3279.5) {
                                            classes[0] = 0; 
                                            classes[1] = 2; 
                                        } else {
                                            classes[0] = 4; 
                                            classes[1] = 0; 
                                        }
                                    } else {
                                        classes[0] = 0; 
                                        classes[1] = 10; 
                                    }
                                } else {
                                    if (features[2] <= 11997.0) {
                                        classes[0] = 8; 
                                        classes[1] = 0; 
                                    } else {
                                        classes[0] = 0; 
                                        classes[1] = 1; 
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[9] <= 3632.5) {
                            if (features[6] <= 3.0) {
                                classes[0] = 3; 
                                classes[1] = 0; 
                            } else {
                                classes[0] = 0; 
                                classes[1] = 97; 
                            }
                        } else {
                            classes[0] = 3; 
                            classes[1] = 0; 
                        }
                    }
                }
            }
        }
    } else {
        if (features[5] >= -45.0) {
            return 1;
        }

        if (features[10] <= 5694.0) {
            classes[0] = 309; 
            classes[1] = 0; 
        } else {
            if (features[4] <= 5681.5) {
                classes[0] = 308; 
                classes[1] = 0; 
            } else {
                if (features[9] <= 2651.0) {
                    classes[0] = 106; 
                    classes[1] = 0; 
                } else {
                    if (features[3] <= 2664.0) {
                        classes[0] = 102; 
                        classes[1] = 0; 
                    } else {
                        if (features[5] <= -68.5) {
                            if (features[9] <= 3560.0) {
                                if (features[3] <= 3573.0) {
                                    if (features[9] <= 3172.5) {
                                        if (features[1] <= 89.5) {
                                            if (features[10] <= 6210.0) {
                                                classes[0] = 1; 
                                                classes[1] = 0; 
                                            } else {
                                                classes[0] = 0; 
                                                classes[1] = 17; 
                                            }
                                        } else {
                                            classes[0] = 0; 
                                            classes[1] = 190; 
                                        }
                                    } else {
                                        if (features[6] <= 1269.5) {
                                            if (features[8] <= 20041.0) {
                                                if (features[4] <= 6678.5) {
                                                    if (features[6] <= 23.0) {
                                                        classes[0] = 1; 
                                                        classes[1] = 0; 
                                                    } else {
                                                        classes[0] = 0; 
                                                        classes[1] = 21; 
                                                    }
                                                } else {
                                                    classes[0] = 0; 
                                                    classes[1] = 79; 
                                                }
                                            } else {
                                                if (features[8] <= 24160.5) {
                                                    classes[0] = 1; 
                                                    classes[1] = 0; 
                                                } else {
                                                    classes[0] = 0; 
                                                    classes[1] = 2; 
                                                }
                                            }
                                        } else {
                                            if (features[3] <= 3320.5) {
                                                if (features[9] <= 3266.5) {
                                                    classes[0] = 0; 
                                                    classes[1] = 33; 
                                                } else {
                                                    if (features[2] <= 7880.5) {
                                                        if (features[8] <= 7266.5) {
                                                            if (features[6] <= 64040.0) {
                                                                if (features[5] <= -71.5) {
                                                                    classes[0] = 1; 
                                                                    classes[1] = 0; 
                                                                } else {
                                                                    classes[0] = 0; 
                                                                    classes[1] = 6; 
                                                                }
                                                            } else {
                                                                if (features[2] <= 1809.0) {
                                                                    classes[0] = 0; 
                                                                    classes[1] = 1; 
                                                                } else {
                                                                    classes[0] = 6; 
                                                                    classes[1] = 0; 
                                                                }
                                                            }
                                                        } else {
                                                            classes[0] = 0; 
                                                            classes[1] = 23; 
                                                        }
                                                    } else {
                                                        if (features[6] <= 2464096.0) {
                                                            if (features[0] <= 165584.0) {
                                                                if (features[10] <= 6671.0) {
                                                                    if (features[1] <= 133.5) {
                                                                        classes[0] = 5; 
                                                                        classes[1] = 0; 
                                                                    } else {
                                                                        classes[0] = 0; 
                                                                        classes[1] = 1; 
                                                                    }
                                                                } else {
                                                                    if (features[2] <= 9912.0) {
                                                                        if (features[6] <= 12423.5) {
                                                                            classes[0] = 0; 
                                                                            classes[1] = 2; 
                                                                        } else {
                                                                            classes[0] = 3; 
                                                                            classes[1] = 0; 
                                                                        }
                                                                    } else {
                                                                        classes[0] = 0; 
                                                                        classes[1] = 6; 
                                                                    }
                                                                }
                                                            } else {
                                                                classes[0] = 7; 
                                                                classes[1] = 0; 
                                                            }
                                                        } else {
                                                            classes[0] = 0; 
                                                            classes[1] = 4; 
                                                        }
                                                    }
                                                }
                                            } else {
                                                if (features[9] <= 3232.0) {
                                                    if (features[10] <= 7617.5) {
                                                        classes[0] = 6; 
                                                        classes[1] = 0; 
                                                    } else {
                                                        classes[0] = 0; 
                                                        classes[1] = 1; 
                                                    }
                                                } else {
                                                    if (features[6] <= 1362.0) {
                                                        classes[0] = 1; 
                                                        classes[1] = 0; 
                                                    } else {
                                                        if (features[2] <= 663.5) {
                                                            if (features[9] <= 3410.5) {
                                                                classes[0] = 0; 
                                                                classes[1] = 1; 
                                                            } else {
                                                                classes[0] = 1; 
                                                                classes[1] = 0; 
                                                            }
                                                        } else {
                                                            if (features[10] <= 6396.0) {
                                                                if (features[3] <= 3375.5) {
                                                                    classes[0] = 2; 
                                                                    classes[1] = 0; 
                                                                } else {
                                                                    classes[0] = 0; 
                                                                    classes[1] = 15; 
                                                                }
                                                            } else {
                                                                classes[0] = 0; 
                                                                classes[1] = 93; 
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[6] <= 866016.0) {
                                        if (features[9] <= 3307.5) {
                                            classes[0] = 3; 
                                            classes[1] = 0; 
                                        } else {
                                            if (features[3] <= 3594.5) {
                                                if (features[10] <= 6386.0) {
                                                    classes[0] = 0; 
                                                    classes[1] = 2; 
                                                } else {
                                                    classes[0] = 4; 
                                                    classes[1] = 0; 
                                                }
                                            } else {
                                                if (features[2] <= 2404.0) {
                                                    classes[0] = 1; 
                                                    classes[1] = 0; 
                                                } else {
                                                    classes[0] = 0; 
                                                    classes[1] = 29; 
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[5] <= -70.5) {
                                            if (features[3] <= 3647.5) {
                                                if (features[2] <= 4853.5) {
                                                    classes[0] = 0; 
                                                    classes[1] = 1; 
                                                } else {
                                                    classes[0] = 2; 
                                                    classes[1] = 0; 
                                                }
                                            } else {
                                                classes[0] = 7; 
                                                classes[1] = 0; 
                                            }
                                        } else {
                                            if (features[4] <= 6280.5) {
                                                classes[0] = 1; 
                                                classes[1] = 0; 
                                            } else {
                                                classes[0] = 0; 
                                                classes[1] = 2; 
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[8] <= 6307.0) {
                                    if (features[4] <= 6759.0) {
                                        if (features[1] <= 106.5) {
                                            classes[0] = 17; 
                                            classes[1] = 0; 
                                        } else {
                                            if (features[8] <= 2930.0) {
                                                classes[0] = 2; 
                                                classes[1] = 0; 
                                            } else {
                                                classes[0] = 0; 
                                                classes[1] = 1; 
                                            }
                                        }
                                    } else {
                                        if (features[7] <= 106.5) {
                                            classes[0] = 0; 
                                            classes[1] = 6; 
                                        } else {
                                            if (features[8] <= 4386.0) {
                                                classes[0] = 0; 
                                                classes[1] = 1; 
                                            } else {
                                                classes[0] = 3; 
                                                classes[1] = 0; 
                                            }
                                        }
                                    }
                                } else {
                                    if (features[0] <= 1194880.0) {
                                        if (features[9] <= 3594.0) {
                                            if (features[7] <= 104.0) {
                                                classes[0] = 4; 
                                                classes[1] = 0; 
                                            } else {
                                                if (features[4] <= 6459.0) {
                                                    classes[0] = 0; 
                                                    classes[1] = 2; 
                                                } else {
                                                    classes[0] = 1; 
                                                    classes[1] = 0; 
                                                }
                                            }
                                        } else {
                                            if (features[4] <= 6051.0) {
                                                classes[0] = 1; 
                                                classes[1] = 0; 
                                            } else {
                                                if (features[3] <= 3301.0) {
                                                    classes[0] = 1; 
                                                    classes[1] = 0; 
                                                } else {
                                                    if (features[7] <= 141.0) {
                                                        classes[0] = 0; 
                                                        classes[1] = 31; 
                                                    } else {
                                                        if (features[7] <= 153.0) {
                                                            classes[0] = 1; 
                                                            classes[1] = 0; 
                                                        } else {
                                                            classes[0] = 0; 
                                                            classes[1] = 1; 
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        classes[0] = 3; 
                                        classes[1] = 0; 
                                    }
                                }
                            }
                        } else {
                            if (features[3] <= 3631.5) {
                                if (features[3] <= 3223.5) {
                                    if (features[9] <= 3414.0) {
                                        if (features[10] <= 6083.0) {
                                            if (features[10] <= 6075.5) {
                                                classes[0] = 0; 
                                                classes[1] = 85; 
                                            } else {
                                                classes[0] = 1; 
                                                classes[1] = 0; 
                                            }
                                        } else {
                                            classes[0] = 0; 
                                            classes[1] = 1445; 
                                        }
                                    } else {
                                        if (features[0] <= 19457.5) {
                                            classes[0] = 2; 
                                            classes[1] = 0; 
                                        } else {
                                            classes[0] = 0; 
                                            classes[1] = 87; 
                                        }
                                    }
                                } else {
                                    if (features[2] <= 272.0) {
                                        if (features[0] <= 345536.0) {
                                            classes[0] = 0; 
                                            classes[1] = 43; 
                                        } else {
                                            classes[0] = 11; 
                                            classes[1] = 0; 
                                        }
                                    } else {
                                        if (features[5] <= -60.5) {
                                            if (features[4] <= 6656.0) {
                                                if (features[4] <= 6463.0) {
                                                    if (features[3] <= 3561.0) {
                                                        classes[0] = 0; 
                                                        classes[1] = 92; 
                                                    } else {
                                                        if (features[4] <= 6237.5) {
                                                            classes[0] = 0; 
                                                            classes[1] = 7; 
                                                        } else {
                                                            classes[0] = 1; 
                                                            classes[1] = 0; 
                                                        }
                                                    }
                                                } else {
                                                    if (features[10] <= 7498.0) {
                                                        if (features[1] <= 88.5) {
                                                            classes[0] = 1; 
                                                            classes[1] = 0; 
                                                        } else {
                                                            if (features[4] <= 6653.0) {
                                                                classes[0] = 0; 
                                                                classes[1] = 26; 
                                                            } else {
                                                                classes[0] = 1; 
                                                                classes[1] = 0; 
                                                            }
                                                        }
                                                    } else {
                                                        if (features[1] <= 98.5) {
                                                            classes[0] = 4; 
                                                            classes[1] = 0; 
                                                        } else {
                                                            if (features[2] <= 1600.0) {
                                                                classes[0] = 2; 
                                                                classes[1] = 0; 
                                                            } else {
                                                                if (features[10] <= 7861.5) {
                                                                    classes[0] = 0; 
                                                                    classes[1] = 8; 
                                                                } else {
                                                                    if (features[1] <= 101.5) {
                                                                        classes[0] = 0; 
                                                                        classes[1] = 1; 
                                                                    } else {
                                                                        classes[0] = 2; 
                                                                        classes[1] = 0; 
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            } else {
                                                if (features[1] <= 155.5) {
                                                    if (features[10] <= 6592.5) {
                                                        if (features[10] <= 6540.5) {
                                                            if (features[0] <= 1.0) {
                                                                if (features[2] <= 8859.5) {
                                                                    classes[0] = 0; 
                                                                    classes[1] = 2; 
                                                                } else {
                                                                    classes[0] = 1; 
                                                                    classes[1] = 0; 
                                                                }
                                                            } else {
                                                                if (features[2] <= 18041.5) {
                                                                    classes[0] = 0; 
                                                                    classes[1] = 75; 
                                                                } else {
                                                                    if (features[2] <= 18235.5) {
                                                                        classes[0] = 1; 
                                                                        classes[1] = 0; 
                                                                    } else {
                                                                        classes[0] = 0; 
                                                                        classes[1] = 4; 
                                                                    }
                                                                }
                                                            }
                                                        } else {
                                                            if (features[0] <= 3432.5) {
                                                                classes[0] = 3; 
                                                                classes[1] = 0; 
                                                            } else {
                                                                classes[0] = 0; 
                                                                classes[1] = 3; 
                                                            }
                                                        }
                                                    } else {
                                                        if (features[0] <= 105472.0) {
                                                            classes[0] = 0; 
                                                            classes[1] = 222; 
                                                        } else {
                                                            if (features[0] <= 107688.0) {
                                                                classes[0] = 1; 
                                                                classes[1] = 0; 
                                                            } else {
                                                                if (features[2] <= 15287.0) {
                                                                    if (features[8] <= 16652.0) {
                                                                        if (features[5] <= -67.5) {
                                                                            if (features[10] <= 6967.0) {
                                                                                if (features[4] <= 7050.0) {
                                                                                    classes[0] = 0; 
                                                                                    classes[1] = 1; 
                                                                                } else {
                                                                                    classes[0] = 1; 
                                                                                    classes[1] = 0; 
                                                                                }
                                                                            } else {
                                                                                classes[0] = 0; 
                                                                                classes[1] = 13; 
                                                                            }
                                                                        } else {
                                                                            classes[0] = 0; 
                                                                            classes[1] = 98; 
                                                                        }
                                                                    } else {
                                                                        if (features[5] <= -62.5) {
                                                                            classes[0] = 0; 
                                                                            classes[1] = 3; 
                                                                        } else {
                                                                            classes[0] = 1; 
                                                                            classes[1] = 0; 
                                                                        }
                                                                    }
                                                                } else {
                                                                    if (features[8] <= 2119.0) {
                                                                        classes[0] = 1; 
                                                                        classes[1] = 0; 
                                                                    } else {
                                                                        if (features[9] <= 3525.0) {
                                                                            classes[0] = 0; 
                                                                            classes[1] = 9; 
                                                                        } else {
                                                                            classes[0] = 1; 
                                                                            classes[1] = 0; 
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[2] <= 11655.5) {
                                                        classes[0] = 1; 
                                                        classes[1] = 0; 
                                                    } else {
                                                        classes[0] = 0; 
                                                        classes[1] = 3; 
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[8] <= 23218.0) {
                                                classes[0] = 0; 
                                                classes[1] = 814; 
                                            } else {
                                                if (features[10] <= 7984.0) {
                                                    classes[0] = 0; 
                                                    classes[1] = 7; 
                                                } else {
                                                    classes[0] = 1; 
                                                    classes[1] = 0; 
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[4] <= 7452.0) {
                                    if (features[6] <= 1092992.0) {
                                        classes[0] = 0; 
                                        classes[1] = 43; 
                                    } else {
                                        classes[0] = 2; 
                                        classes[1] = 0; 
                                    }
                                } else {
                                    classes[0] = 6; 
                                    classes[1] = 0; 
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    static int index = 0;
    static int i;
    for (i = 0; i < 2; i++) {
        index = classes[i] > classes[index] ? i : index;
    }
    return index;
}

// int main(int argc, const char * argv[]) {

//     /* Features: */
//     double features[argc-1];
//     int i;
//     for (i = 1; i < argc; i++) {
//         features[i-1] = atof(argv[i]);
//     }

//     /* Prediction: */
//     printf("%d", predict(features));
//     return 0;

// }
