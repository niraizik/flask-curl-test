from flask import Flask, request
app = Flask(__name__)


@app.route('/api/set-status', methods=['POST'])
def hello():
    return request.json

if __name__ == '__main__':
    from werkzeug.serving import WSGIRequestHandler
    WSGIRequestHandler.protocol_version = "HTTP/1.1"
    app.run(host='0.0.0.0', port=80)