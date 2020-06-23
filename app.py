from flask import Flask, request, g
import time
import math
import sys
app = Flask(__name__)


@app.route('/api/set-status', methods=['POST'])
def hello():
    return request.json

@app.after_request
def after_request_func(response):

    """ 
    This function will run after a request, as long as no exceptions occur.
    It must take and return the same parameter - an instance of response_class.
    This is a good place to do some application cleanup.
    """

    t = math.floor(time.time())
    if t % 5 == 0:
        request.close()
        print("close", file=sys.stderr)
    return response

if __name__ == '__main__':
    from werkzeug.serving import WSGIRequestHandler
    WSGIRequestHandler.protocol_version = "HTTP/1.1"
    app.run(host='0.0.0.0', port=80)